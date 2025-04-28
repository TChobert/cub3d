/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:06:48 by tchobert          #+#    #+#             */
/*   Updated: 2025/04/28 14:06:59 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_game.h"

static bool	is_in_map(t_game_data *game_data, double new_x, double new_y)
{
	const int	map_length = (int)game_data->map.map_length;
	const int	map_width = (int)game_data->map.map_width;
	const int	map_x = (int)new_x;
	const int	map_y = (int)new_y;

	if (map_x < 0.98 || map_y < 0.98 || map_x >= (map_length - 1.2)
		|| map_y >= (map_width - 1.2))
		return (false);
	return (true);
}

static bool is_not_in_wall(t_game_data *game_data, double new_x, double new_y)
{
    const int map_x = (int)new_x;
    const int map_y = (int)new_y;
    const double tolerance = 0.15;  // Distance minimale d'approche du mur (ajuste cette valeur)
    
    // Vérifier directement la case où le joueur se trouve
    if (game_data->map.map[map_y][map_x] == '1') {
        return false;  // Le joueur est déjà dans un mur, mouvement invalide
    }

    // Initialiser les variables pour parcourir autour du joueur
    double i = -tolerance;
    
    // Vérifier autour du joueur sur une petite zone, en utilisant une boucle while
    while (i <= tolerance) {
        double j = -tolerance;

        // Boucle interne pour vérifier dans la direction Y
        while (j <= tolerance) {
            int check_x = (int)(new_x + i);
            int check_y = (int)(new_y + j);

            // Vérifier que les coordonnées sont dans les limites de la carte
            if (check_x >= 0 && check_x < (int)game_data->map.map_length &&
                check_y >= 0 && check_y < (int)game_data->map.map_width) {
                // Si un mur est trop proche, retourner false
                if (game_data->map.map[check_y][check_x] == '1') {
                    return false; // Le joueur est trop proche d'un mur
                }
            }
            j += 0.05;  // Pas de vérification pour Y
        }
        i += 0.05;  // Pas de vérification pour X
    }

    return true;  // Le mouvement est valide si aucun mur n'est trop proche
}

// static bool	is_not_in_wall(t_game_data *game_data, double new_x, double new_y)
// {
// 	const int	map_x = (int)new_x;
// 	const int	map_y = (int)new_y;

// 	if (game_data->map.map[map_y][map_x] == '1')
// 		return (false);
// 	return (true);
// }

bool is_valid_move(t_game_data *game_data, double new_x, double new_y)
{
	if (is_in_map(game_data, new_x, new_y) == false)
		return (false);
	return (is_not_in_wall(game_data, new_x, new_y));
}
