#define BIT3 3
unsigned char status;

status = 0b00110101;
status = status | 0xFA;

/*
*	status	  =  0b00110101
*	0XFA 	  =  0b11111010
*	
*	or result =  0b11111111
*/

status = status & 20;

/*
*	status	   =  0b11111111
*	20 	   =  0b00010100
*	
*	and result =  0b00010100
*/

status |= (1 << 6);

/*
*	status	   =  0b00010100
*	(1 << 6)   =  0b01000000
*	
*	or result  =  0b01010100
*/

status &= ~(1 << BIT3)

/*
*       (1 << BIT3) =  0b00001000
*      ~(1 << BIT3) =  0b11110111
*	status	    =  0b01010100
*	
*	and result  =  0b01010100
*/
status |= (1 << BIT3)

/*
*       (1 << BIT3) =  0b00001000
*	status	    =  0b01010100
*	
*	or result   =  0b01011100
*/
