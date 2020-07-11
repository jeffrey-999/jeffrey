/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonam <yonam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 22:03:15 by yonam             #+#    #+#             */
/*   Updated: 2020/07/07 22:12:38 by yonam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size);
void	swap(int *a, int *b);

void	swap(int *a, int *b)
{
	int t;

	t = *a;
	*a = *b;
	*b = t;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = size - 1;
		while (j > i)
		{
			if (*(tab + j) < *(tab + j - 1))
			{
				swap(tab + j, tab + j - 1);
			}
			j--;
		}
		i++;
	}
}
