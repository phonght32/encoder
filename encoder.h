// MIT License

// Copyright (c) 2023 phonght32

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef __ENCODER_H__
#define __ENCODER_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "err_code.h"

typedef err_code_t (*encoder_func_start)(void);
typedef err_code_t (*encoder_func_stop)(void);
typedef err_code_t (*encoder_func_set_counter)(uint32_t value);
typedef err_code_t (*encoder_func_get_counter)(uint32_t *value);
typedef err_code_t (*encoder_func_set_mode)(uint8_t mode);

typedef struct encoder *encoder_handle_t;

typedef struct {
	uint32_t 					max_reload;             /*!< Max reload value */
	encoder_func_start 		start;					/*!< Function start encoder */
	encoder_func_stop 			stop;					/*!< Function stop encoder */
	encoder_func_set_counter 	set_counter;			/*!< Function set counter */
	encoder_func_get_counter 	get_counter;			/*!< Function get counter */
	encoder_func_set_mode		set_mode;				/*!< Function set mode counter */
} encoder_cfg_t;

/*
 * @brief   Initialize encoder with default parameters.
 *
 * @note    This function must be called first.
 *
 * @param   None.
 *
 * @return
 *      - Handle structure: Success.
 *      - Others:           Fail.
 */
encoder_handle_t encoder_init(void);

/*
 * @brief   Set configuration parameters.
 *
 * @param 	handle Handle structure.
 * @param   cfg Configuration structure.
 *
 * @return
 *      - ERR_CODE_SUCCESS: Success.
 *      - Others:           Fail.
 */
err_code_t encoder_set_config(encoder_handle_t handle, encoder_cfg_t cfg);

/*
 * @brief   Configure encoder to run.
 *
 * @param 	handle Handle structure.
 *
 * @return
 *      - ERR_CODE_SUCCESS: Success.
 *      - Others:           Fail.
 */
err_code_t encoder_config(encoder_handle_t handle);

/*
 * @brief   Start encoder.
 *
 * @param   handle Handle structure.
 *
 * @return
 *      - ERR_CODE_SUCCESS: Success.
 *      - Others:           Fail.
 */
err_code_t encoder_start(encoder_handle_t handle);

/*
 * @brief   Stop encoder.
 *
 * @param   handle Handle structure.
 *
 * @return
 *      - ERR_CODE_SUCCESS: Success.
 *      - Others:           Fail.
 */
err_code_t encoder_stop(encoder_handle_t handle);

/*
 * @brief   Get encoder counter value.
 *
 * @param   handle Handle structure.
 * @param   value Counter value.
 *
 * @return
 *      - ERR_CODE_SUCCESS: Success.
 *      - Others:           Fail.
 */
err_code_t encoder_get_value(encoder_handle_t handle, uint32_t *value);

/*
 * @brief   Set encoder counter value.
 *
 * @param   handle Handle structure.
 * @param   value Counter value.
 *
 * @return
 *      - ERR_CODE_SUCCESS: Success.
 *      - Others:           Fail.
 */
err_code_t encoder_set_value(encoder_handle_t handle, uint32_t value);

/*
 * @brief   Set mode counter.
 *
 * @param   handle Handle structure.
 * @param 	mode Counter mode. 0: Up, 1: Down.
 *
 * @return
 *      - ERR_CODE_SUCCESS: Success.
 *      - Others:           Fail.
 */
err_code_t encoder_set_mode(encoder_handle_t handle, uint8_t mode);


#ifdef __cplusplus
}
#endif

#endif /* __ENCODER_H__ */