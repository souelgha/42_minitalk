/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recepteur_server.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:22:10 by sonouelg          #+#    #+#             */
/*   Updated: 2024/02/01 17:31:16 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"






int main(void) 
{

	printf("server <PID> = <%d>\n", getpid());
    printf("server <%d> en attente du message.\n", getpid());

    while (1) {
        // Boucle infinie
    }

    return 0;
}
