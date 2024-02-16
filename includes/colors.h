/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 14:19:41 by kmendes-          #+#    #+#             */
/*   Updated: 2024/02/15 16:14:50 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

// clear screen
# define CLEAR "\033[2J\033[H"
// \033[38;5;COLORm - Set text color.[0-255] - "\033[38;5;ColorNumberm"
# define FORE_RED "\033[38;5;1m"
// \033[48;5;COLORm: Set background color.[0-255] - "\033[48;5;ColorNumberm"
# define BACK_BLUE "\033[48;5;4m"
# define BACK_DARK "\033[48;5;0m"
# define BACK_RED "\033[48;5;1m"
// printf(RED "hello" CLEAR);
// 1 	Bold/Bright = "\e[1m"
// 2 	Dim = "\e[2m"
// 4 	Underlined = "\e[4m"
// 5 	Blink = "\e[5m"
// 7 	Reverse (invert the foreground and background colors) = "\e[7m"
// 8 	Hidden (useful for passwords) = "\e[8m"
# define BLINK "\033[5m"
# define R_BLINK "\033[25m"

// 0 	Reset all attributes = "\e[0m"
// 21 	Reset bold/bright = "\e[21m"
// 22 	Reset dim = "\e[22m"
// 24 	Reset underlined = "\e[24m"
// 25 	Reset blink = "\e[25m"
// 27 	Reset reverse = "\e[27m"
// 28 	Reset hidden = "\e[28m"
# define RESET "\x1B[0m"
# define RESET_A "\x1B[0m"
# define END	"\x1B[0m\n"

// Definitions of some printf colors
// \033[0;COLORm
# define BLACK "\033[0;30m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"
# define WHITE "\033[0;37m"
# define BOLD_BLACK "\033[30;1m"
# define BOLD_RED "\033[31;1m"
# define BOLD_GREEN "\033[32;1m"
# define BOLD_YELLOW "\033[33;1m"
# define BOLD_BLUE "\033[34;1m"
# define BOLD_PURPLE "\033[35;1m"
# define BOLD_CYAN "\033[36;1m"
# define BOLD_WHITE "\033[37;1m"

# define DARK_BLACK "\033[30;2m"
# define ITALIC_BLACK "\033[30;3m"
# define UNDERLINE_BLACK "\033[30;4m"
# define BLINK_BLACK "\033[30;5m"
# define O_BLINK_BLACK "\033[30;6m"
# define NEG_BLACK "\033[30;7m"
# define INV_BLACK "\033[30;8m"

# define DARK_RED "\033[31;2m"
# define ITALIC_RED "\033[31;3m"
# define UNDERLINE_RED "\033[31;4m"
# define BLINK_RED "\033[31;5m"
# define O_BLINK_RED "\033[31;6m"
# define NEG_RED "\033[31;7m"
# define INV_RED "\033[31;8m"

# define DARK_GREEN "\033[32;2m"
# define ITALIC_GREEN "\033[32;3m"
# define UNDERLINE_GREEN "\033[32;4m"
# define BLINK_GREEN "\033[32;5m"
# define O_BLINK_GREEN "\033[32;6m"
# define NEG_GREEN "\033[32;7m"
# define INV_GREEN "\033[32;8m"

# define DARK_YELLOW "\033[33;2m"
# define ITALIC_YELLOW "\033[33;3m"
# define UNDERLINE_YELLOW "\033[33;4m"
# define BLINK_YELLOW "\033[33;5m"
# define O_BLINK_YELLOW "\033[33;6m"
# define NEG_YELLOW "\033[33;7m"
# define INV_YELLOW "\033[33;8m"

# define DARK_BLUE "\033[34;2m"
# define ITALIC_BLUE "\033[34;3m"
# define UNDERLINE_BLUE "\033[34;4m"
# define BLINK_BLUE "\033[34;5m"
# define O_BLINK_BLUE "\033[34;6m"
# define NEG_BLUE "\033[34;7m"
# define INV_BLUE "\033[34;8m"

# define DARK_PURPLE "\033[35;2m"
# define ITALIC_PURPLE "\033[35;3m"
# define UNDERLINE_PURPLE "\033[35;4m"
# define BLINK_PURPLE "\033[35;5m"
# define O_BLINK_PURPLE "\033[35;6m"
# define NEG_PURPLE "\033[35;7m"
# define INV_PURPLE "\033[35;8m"

# define DARK_CYAN "\033[36;2m"
# define ITALIC_CYAN "\033[36;3m"
# define UNDERLINE_CYAN "\033[36;4m"
# define BLINK_CYAN "\033[36;5m"
# define O_BLINK_CYAN "\033[36;6m"
# define NEG_CYAN "\033[36;7m"
# define INV_CYAN "\033[36;8m"

# define DARK_WHITE "\033[37;2m"
# define ITALIC_WHITE "\033[37;3m"
# define UNDERLINE_WHITE "\033[37;4m"
# define BLINK_WHITE "\033[37;5m"
# define O_BLINK_WHITE "\033[37;6m"
# define NEG_WHITE "\033[37;7m"
# define INV_WHITE "\033[37;8m"

// Yes, you can control the color of the output on the 
//terminal using ANSI escape codes as well. ANSI escape codes for 
//colors typically use a combination of foreground and background color codes. 
//Here's a brief explanation:
//     \033[38;5;COLORm: Set foreground text color 
//to the specified 8-bit color. 
//Replace COLOR with a value between 0 and 255.
//     \033[48;5;COLORm: Set background color to the specified 8-bit color. 
//Replace COLOR with a value between 0 and 255.
// Here's an example that sets the text color to red (color code 196) and 
//the background color to yellow (color code 226):
// printf("\033[38;5;196m\033[48;5;226mHello, colored world!\033[0m\n");

#endif //COLORS_H
