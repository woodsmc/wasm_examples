#include <stdio.h>
#include "wasm_c_api.h"
#include "wasm_export.h"
#include "bh_platform.h"
#include <stdint.h>
#include <string.h>
#include "bh_read_file.h"



#define WASM_FILE "../../wasm/b.wasm"

#define GLOBAL_HEAP_BUFFER_SIZE (512*1024)
#define ERROR_BUFFER_SIZE (128)

typedef void (*TFunctionPtr)(void);

TFunctionPtr invoke_get_ref(wasm_module_inst_t module_instance, wasm_exec_env_t exec_env) {
	const char* WASM_FUNCTION = "get_ref";
	printf("look up a function [%s]\n", WASM_FUNCTION);
	wasm_function_inst_t func = wasm_runtime_lookup_function(module_instance, WASM_FUNCTION);
	if (!func) {
		printf("couldn't find function [%s]\n", WASM_FUNCTION);
		return false;
	}
	printf(">function found!\n");	
	wasm_val_t parameters[] = {
		{.kind = WASM_EXTERNREF
		,.of.ref = NULL}
	};

	printf(">calling function with parameters(%p)\n", parameters[0].of.ref);
	bool executed_ok = wasm_runtime_call_wasm_a(exec_env, func, 1, &parameters[0], 0, NULL);
	if (!executed_ok) {
		printf("call failed!\n");
		return NULL;
	}
	
	return (TFunctionPtr) parameters[0].of.ref;
}

void invoke_set_ref(wasm_module_inst_t module_instance, wasm_exec_env_t exec_env, void* ptr) {
	const char* WASM_FUNCTION = "set_ref";
	printf("look up a function [%s]\n", WASM_FUNCTION);
	wasm_function_inst_t func = wasm_runtime_lookup_function(module_instance, WASM_FUNCTION);
	if (!func) {
		printf("couldn't find function [%s]\n", WASM_FUNCTION);
		return;
	}
	printf(">function found!\n");	
	wasm_val_t parameters[] = {
		{.kind = WASM_EXTERNREF
		,.of.ref = ptr}
	};

	printf(">calling function with parameters(%p)\n", parameters[0].of.ref);
	bool executed_ok = wasm_runtime_call_wasm_a(exec_env, func, 0, NULL, 1, &parameters[0]);
	if (!executed_ok) {
		printf("call failed!\n");
		return;
	}	
}




void function_a(void) {
	printf("This is %s \n", __func__);
}


int main(void) {
	printf("Starting\n");
	// structures
	wasm_module_t module = NULL;
	wasm_module_inst_t module_inst = NULL;
	wasm_exec_env_t exec_env = NULL;
	uint32_t stack_size = 8092;
	uint32_t heap_size = 8092;



	static uint8_t global_heap_buffer[GLOBAL_HEAP_BUFFER_SIZE];
	static char error_buf[ERROR_BUFFER_SIZE];
	static RuntimeInitArgs args;
	memset(&args, 0, sizeof(RuntimeInitArgs));
	memset(global_heap_buffer, 0, GLOBAL_HEAP_BUFFER_SIZE);
	memset(error_buf, 0, ERROR_BUFFER_SIZE);

	args.mem_alloc_type = Alloc_With_Pool;
	args.mem_alloc_option.pool.heap_buf = global_heap_buffer;
	args.mem_alloc_option.pool.heap_size = GLOBAL_HEAP_BUFFER_SIZE;	
	args.native_module_name = "host";
	args.n_native_symbols = 0;
	args.native_symbols = NULL;


	// buffer space
	
	printf("initialize WAMR\n");
	int response = wasm_runtime_full_init(&args);
	printf(">wasm init with %d\n", response);
	if(!response) {
		printf("error!\n");
		return -1;
	}
	wasm_runtime_set_log_level(WASM_LOG_LEVEL_VERBOSE);

	printf("load wasm in WAMR\n");
	uint32_t buffer_size = 0;
	char* wasm_data = bh_read_file_to_buffer(WASM_FILE, &buffer_size);
	if(!wasm_data) {
		printf("can't open %s!\n", WASM_FILE);
		goto fail;
	} else {
		printf(">loaded wasm into memory file %s size %u at %p\n", WASM_FILE, buffer_size, wasm_data);
		char c = wasm_data[0];
		printf("c is %d\n", c);
	}

	module = wasm_runtime_load(wasm_data, buffer_size, error_buf, ERROR_BUFFER_SIZE);
	if (! module) {
		printf("module couldn't be loaded [%s]\n", error_buf);
		goto fail;
	}
	printf(">module created\n");

	module_inst = wasm_runtime_instantiate(module, stack_size, heap_size, error_buf, ERROR_BUFFER_SIZE);
	if (!module_inst) {
		printf("module creation failed\n");
		goto fail;
	}
	printf(">module instance created\n");

    exec_env = wasm_runtime_create_exec_env(module_inst, stack_size);
    if (!exec_env) {
        printf("Create wasm execution environment failed.\n");
        goto fail;
	}
	printf(">execution environment created\n");

	// The good stuff is here.... 
	TFunctionPtr ptr = function_a;

	printf("set %p\n", exec_env);
	invoke_set_ref(module_inst, exec_env, ptr);
	TFunctionPtr ptrBack = invoke_get_ref(module_inst, exec_env);
	printf("got %p\n", ptrBack);
	ptrBack();


	// the good stop stops here.... 


	goto skip_fail;
	fail:
	printf("fail recovery\n");
	skip_fail:
	printf("de-initialize WAMR\n");


	if (module_inst) {
		wasm_runtime_deinstantiate(module_inst);
	}
	if (module) {
		wasm_runtime_unload(module);
	}
	if ( wasm_data ) {
		BH_FREE(wasm_data);
	}
	wasm_runtime_destroy();

	return 0;
}

