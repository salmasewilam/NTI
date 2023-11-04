/*
 * fingerprint.h
 *
 * Created: 11/04/23 10:20:20 AM
 *  Author: USER
 */ 


#ifndef FINGERPRINT_H_
#define FINGERPRINT_H_

typedef enum {FINGER_COL_SUCCESS=0,
	ERROR_WHEN_RECIEVING_PACKAGE,
	no_finger_on_the_sensor,
	fail_to_enroll_the_finger,
	over_disorderly_fingerprint_image=0x06,
	lackness_of_character_point,
	finger_doesnt_match,
	fail_to_find_the_matching_finger,
	fail_to_combine_the_character_files,
	addressing_PageID_is_beyond_the_finger_library,
	error_when_reading_template_from_library,
	error_when_uploading_template,
	Module_cant_receive_the_following_data_packages,
	error_when_uploading_image,
	fail_to_delete_the_template,
	fail_to_clear_finger_library,
	wrong_password=0x13,
	lackness_of_valid_primary_image=0x15,
	error_when_writing_flash=0x18,
	No_definition_error,
	invalid_register_number=0x1A,
	incorrect_configuration_of_register,
	wrong_notepad_page_number,
	fail_to_operate_the_communication_port,
	}FINGERP_ERROR_t;



#endif /* FINGERPRINT_H_ */