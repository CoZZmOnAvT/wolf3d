/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sgl_draw_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <pgritsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 16:10:00 by pgritsen          #+#    #+#             */
/*   Updated: 2018/01/12 12:11:57 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sgl_private.h"

void	sgl_draw_str(char *string, t_font *font_data,
						t_point align, SDL_Surface *surface)
{
	TTF_Font	*font;
	SDL_Color	color;
	SDL_Surface	*text_surf;

	if (!(font = sgl_get_font(font_data)))
		return ;
	color = (SDL_Color){.r = font_data->color / 0x10000 % 256,
						.g = font_data->color / 0x100 % 256,
						.b = font_data->color % 256,
						.a = font_data->color / 0x1000000 % 256};
	text_surf = TTF_RenderUTF8_Blended(font, string, color);
	SDL_BlitSurface(text_surf, NULL, surface,
					&(SDL_Rect){(int)align.x, (int)align.y, 0, 0});
	SDL_FreeSurface(text_surf);
}
