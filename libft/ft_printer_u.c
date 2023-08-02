/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:09:14 by tgernez           #+#    #+#             */
/*   Updated: 2022/11/19 18:01:09 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printer_u(unsigned int nb)
{
	int	len;

	len = 0;
	ft_putnbr_ui(nb, &len);
	return (len);
}