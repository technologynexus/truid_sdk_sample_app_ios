//
//  Constants.h
//  TruId IPhone 
//
//  Created by Samuel Erdtman on 5/10/10.
//  Copyright 2010 PortWise. All rights reserved.
//

#define CHALLENGE_LENGTH	8
#define SEED_LENGTH			20
#define PIN_LENGTH			6
#define OTP_LENGTH			6
#define NUMBER_OF_HASHINGS	17

#define VALID_SEED_CHARACTERS		@"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLKMNOPQRSTUVWXYZ0123456789"
#define SEED_DELIMITER_CHARACTER	@"-"

#ifdef DEBUG

#	define DLog(fmt, ...) NSLog((@"%s [Line %d] : " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);

#else

#	define DLog(fmt, ...)

#endif