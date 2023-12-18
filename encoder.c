#include "stdlib.h"
#include "encoder.h"

typedef struct encoder {
	uint32_t 					max_reload;				/*!< Max reload value */
	uint8_t  					is_run; 				/*!< Running status */
	encoder_func_start 		start;					/*!< Function start encoder */
	encoder_func_stop 			stop;					/*!< Function stop encoder */
	encoder_func_set_counter 	set_counter;			/*!< Function set counter */
	encoder_func_get_counter 	get_counter;			/*!< Function get counter */
	encoder_func_set_mode		set_mode;				/*!< Function set mode counter */
} encoder_t;

encoder_handle_t encoder_init(void)
{
	encoder_handle_t handle = calloc(1, sizeof(encoder_t));
	if (handle == NULL)
	{
		return NULL;
	}

	return handle;
}

err_code_t encoder_set_config(encoder_handle_t handle, encoder_cfg_t cfg)
{
	/* Check if handle structure is NULL */
	if (handle == NULL)
	{
		return ERR_CODE_NULL_PTR;
	}

	handle->max_reload = cfg.max_reload;
	handle->is_run = 0;
	handle->start = cfg.start;
	handle->stop = cfg.stop;
	handle->set_counter = cfg.set_counter;
	handle->get_counter = cfg.get_counter;
	handle->set_mode = cfg.set_mode;

	return ERR_CODE_SUCCESS;
}

err_code_t encoder_config(encoder_handle_t handle)
{
	/* Check if handle structure is NULL */
	if (handle == NULL)
	{
		return ERR_CODE_NULL_PTR;
	}

	/* Nothing to do */

	return ERR_CODE_SUCCESS;
}

err_code_t encoder_start(encoder_handle_t handle)
{
	/* Check if handle structure is NULL */
	if (handle == NULL)
	{
		return ERR_CODE_NULL_PTR;
	}

	err_code_t err;

	err = handle->start();
	if (err != ERR_CODE_SUCCESS)
	{
		return err;
	}

	handle->is_run = 1;

	return ERR_CODE_SUCCESS;
}

err_code_t encoder_stop(encoder_handle_t handle)
{
	/* Check if handle structure is NULL */
	if (handle == NULL)
	{
		return ERR_CODE_NULL_PTR;
	}

	err_code_t err;

	err = handle->stop();
	if (err != ERR_CODE_SUCCESS)
	{
		return err;
	}

	handle->is_run = 0;

	return ERR_CODE_SUCCESS;
}

err_code_t encoder_get_value(encoder_handle_t handle, uint32_t *value)
{
	/* Check if handle structure is NULL */
	if (handle == NULL)
	{
		return ERR_CODE_NULL_PTR;
	}

	err_code_t err;

	err = handle->get_counter(value);
	if (err != ERR_CODE_SUCCESS)
	{
		return err;
	}

	return ERR_CODE_SUCCESS;
}

err_code_t encoder_set_value(encoder_handle_t handle, uint32_t value)
{
	/* Check if handle structure is NULL */
	if (handle == NULL)
	{
		return ERR_CODE_NULL_PTR;
	}

	err_code_t err;

	err = handle->set_counter(value);
	if (err != ERR_CODE_SUCCESS)
	{
		return err;
	}

	return ERR_CODE_SUCCESS;
}

err_code_t encoder_set_mode(encoder_handle_t handle, uint8_t mode)
{
	/* Check if handle structure is NULL */
	if (handle == NULL)
	{
		return ERR_CODE_NULL_PTR;
	}

	err_code_t err;

	err = handle->set_mode(mode);
	if (err != ERR_CODE_SUCCESS)
	{
		return err;
	}

	return ERR_CODE_SUCCESS;
}