#include "py/nlr.h"
#include "py/obj.h"
#include "py/runtime.h"
#include "py/binary.h"
//#include "portmodules.h"

#include <esp_sleep.h>
//#include <esp_deep_sleep.h>

//STATIC const mp_map_elem_t deep_sleep_globals_table[] = {
//    { MP_OBJ_NEW_QSTR(MP_QSTR___name__), MP_OBJ_NEW_QSTR(MP_QSTR_deep_sleep) },
//    { MP_OBJ_NEW_QSTR(MP_QSTR_hello), (mp_obj_t)&deep_sleep_hello_obj },
//    { MP_OBJ_NEW_QSTR(MP_QSTR_deep_sleep_start_time), (mp_obj_t)&deep_sleep_start_time },
//};

//STATIC MP_DEFINE_CONST_DICT (
//    mp_module_deep_sleep_globals,
//    deep_sleep_globals_table
//);

//const mp_obj_module_t mp_module_deep_sleep = {
//    .base = { &mp_type_module },
//    .globals = (mp_obj_dict_t*)&mp_module_deep_sleep_globals,
//};

STATIC mp_obj_t deep_sleep_hello(void) {
    printf("Hello world!\n");
    return mp_const_none;
}
STATIC MP_DEFINE_CONST_FUN_OBJ_0(deep_sleep_hello_obj, deep_sleep_hello);

STATIC mp_obj_t deep_sleep_sleep_timeout(mp_obj_t timeout) {
    int to = mp_obj_get_int(timeout);
    printf("Starting sleep!\n");
    esp_sleep_enable_timer_wakeup(to);
    esp_deep_sleep_start();
    return mp_const_none;
}
STATIC MP_DEFINE_CONST_FUN_OBJ_1(deep_sleep_sleep_timeout_obj, deep_sleep_sleep_timeout);

STATIC const mp_map_elem_t deep_sleep_globals_table[] = {
    { MP_OBJ_NEW_QSTR(MP_QSTR___name__), MP_OBJ_NEW_QSTR(MP_QSTR_deep_sleep) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_hello), (mp_obj_t)&deep_sleep_hello_obj },
    { MP_OBJ_NEW_QSTR(MP_QSTR_sleep_timeout), (mp_obj_t)&deep_sleep_sleep_timeout_obj },
};

STATIC MP_DEFINE_CONST_DICT (
    mp_module_deep_sleep_globals,
    deep_sleep_globals_table
);

const mp_obj_module_t mp_module_deep_sleep = {
    .base = { &mp_type_module },
    .globals = (mp_obj_dict_t*)&mp_module_deep_sleep_globals,
};

