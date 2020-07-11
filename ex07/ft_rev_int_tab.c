/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonam <yonam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 21:52:58 by yonam             #+#    #+#             */
/*   Updated: 2020/07/07 21:53:00 by yonam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size);

void	ft_rev_int_tab(int *tab, int size)
{
	int t;
	int i;
	int r;

	i = 0;
	r = size - 1;
	while (i < r)
	{
		t = *(tab + i);
		*(tab + i) = *(tab + r);
		*(tab + r) = t;
		i++;
		r--;
	}
}
