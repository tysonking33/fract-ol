/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tytang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:51:23 by tytang            #+#    #+#             */
/*   Updated: 2022/11/23 13:51:25 by tytang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

# define MAX_ITERATIONS	80
# define SCROLL_UP		(0x04)
# define SCROLL_DOWN	(0x05)
# define WIDTH			1080
# define HEIGHT			720
# define LEFT_CLK		(0x01)
# define RIGHT_CLK	(0x02)
# define MIDDLE_CLK	(0x03)
# define MLX_SYNC_IMAGE_WRITABLE		1
# define MLX_SYNC_WIN_FLUSH_CMD		2
# define MLX_SYNC_WIN_CMD_COMPLETED	3
# define KEY_ANSI_A			 		(0X00)
# define KEY_ANSI_S			 		(0X01)
# define KEY_ANSI_D			 		(0X02)
# define KEY_ANSI_F			 		(0X03)
# define KEY_ANSI_H			 		(0X04)
# define KEY_ANSI_G			 		(0X05)
# define KEY_ANSI_Z			 		(0X06)
# define KEY_ANSI_X			 		(0X07)
# define KEY_ANSI_C			 		(0X08)
# define KEY_ANSI_V			 		(0X09)
# define KEY_ANSI_B			 		(0X0B)
# define KEY_ANSI_Q			 		(0X0C)
# define KEY_ANSI_W					(0X0D)
# define KEY_ANSI_E			 		(14)
# define KEY_ANSI_R			 		(0X0F)
# define KEY_ANSI_Y			 		(0X10)
# define KEY_ANSI_T			 		(0X11)
# define KEY_ANSI_1			 		(0X12)
# define KEY_ANSI_2			 		(0X13)
# define KEY_ANSI_3			 		(0X14)
# define KEY_ANSI_4			 		(0X15)
# define KEY_ANSI_6			 		(0X16)
# define KEY_ANSI_5			 		(0X17)
# define KEY_ANSI_EQUAL		 		(0X18)
# define KEY_ANSI_9			 		(0X19)
# define KEY_ANSI_7			 		(0X1A)
# define KEY_ANSI_MINUS		 		(0X1B)
# define KEY_ANSI_8			 		(0X1C)
# define KEY_ANSI_0			 		(0X1D)
# define KEY_ANSI_O			 		(0X1F)
# define KEY_ANSI_U			 		(0X20)
# define KEY_ANSI_LEFTBRACKET   	(0X21)
# define KEY_ANSI_I			 		(0X22)
# define KEY_ANSI_P			 		(0X23)
# define KEY_ANSI_L			 		(0X25)
# define KEY_ANSI_J			 		(0X26)
# define KEY_ANSI_QUOTE		 		(0X27)
# define KEY_ANSI_K			 		(0X28)
# define KEY_ANSI_SEMICOLON	 		(0X29)
# define KEY_ANSI_BACKSLASH	 		(0X2A)
# define KEY_ANSI_COMMA		 		(0X2B)
# define KEY_ANSI_SLASH		 		(0X2C)
# define KEY_ANSI_N			 		(0X2D)
# define KEY_ANSI_PERIOD			(0X2F)
# define KEY_ANSI_GRAVE		 		(0X32)
# define KEY_ANSI_KEYPADDECIMAL 	(0X41)
# define KEY_ANSI_KEYPADMULTIPLY	(0X43)
# define KEY_ANSI_KEYPADPLUS		(0X45)
# define KEY_ANSI_KEYPADCLEAR   	(0X47)
# define KEY_ANSI_KEYPADDIVIDE  	(0X4B)
# define KEY_ANSI_KEYPADENTER   	(0X4C)

# define KEY_ANSI_KEYPADEQUALS  	(0X51)
# define KEY_ANSI_KEYPAD0	   		(0X52)
# define KEY_ANSI_KEYPAD1	   		(0X53)
# define KEY_ANSI_KEYPAD2	   		(0X54)
# define KEY_ANSI_KEYPAD3	   		(0X55)
# define KEY_ANSI_KEYPAD4	   		(0X56)
# define KEY_ANSI_KEYPAD5	   		(0X57)
# define KEY_ANSI_KEYPAD6	   		(0X58)
# define KEY_ANSI_KEYPAD7	   		(0X59)
# define KEY_ANSI_KEYPAD8	   		(0X5B)
# define KEY_ANSI_KEYPAD9	   		(0X5C)

/*
** Keycodes for keys that are independent of keyboard layout.
** These ones doesn't follow the ANSI-standard US keyboard.
*/

# define KEY_RETURN			 		(0X24)
# define KEY_TAB					(0X30)
# define KEY_SPACE			  		(0X31)
# define KEY_DELETE			 		(0X33)
# define KEY_ESCAPE			 		(0X35)
# define KEY_COMMAND				(0X37)
# define KEY_SHIFT			  		(0X38)
# define KEY_CAPSLOCK		   		(0X39)
# define KEY_OPTION			 		(0X3A)
# define KEY_CONTROL				(0X3B)
# define KEY_RIGHTSHIFT		 		(0X3C)
# define KEY_RIGHTOPTION			(0X3D)

# define KEY_FUNCTION		   		(0X3F)
# define KEY_F17					(0X40)
# define KEY_VOLUMEUP		   		(0X48)
# define KEY_VOLUMEDOWN		 		(0X49)
# define KEY_MUTE			   		(0X4A)
# define KEY_F18					(0X4F)
# define KEY_F19					(0X50)
# define KEY_F20					(0X5A)
# define KEY_F5				 		(0X60)
# define KEY_F6				 		(0X61)
# define KEY_F7				 		(0X62)
# define KEY_F3				 		(0X63)
# define KEY_F8				 		(0X64)
# define KEY_F9				 		(0X65)
# define KEY_F11					(0X67)
# define KEY_F13					(0X69)
# define KEY_F16					(0X6A)
# define KEY_F14					(0X6B)
# define KEY_F10					(0X6D)
# define KEY_F12					(0X6F)
# define KEY_F15					(0X71)
# define KEY_HELP			   		(0X72)
# define KEY_HOME			   		(0X73)
# define KEY_PAGEUP			 		(0X74)
# define KEY_FORWARDDELETE	  		(0X75)
# define KEY_F4				 		(0X76)
# define KEY_END					(0X77)
# define KEY_F2				 		(0X78)
# define KEY_PAGEDOWN		   		(0X79)
# define KEY_F1				 		(0X7A)
# define KEY_LEFT		  		(0X7B)
# define KEY_RIGHT		 		(0X7C)
# define KEY_DOWN		  		(0X7D)
# define KEY_UP				(126)
#endif
