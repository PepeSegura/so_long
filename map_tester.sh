#!/bin/bash

echo -e "\033[1;32mmap_no_collectibles \033[0m"
./so_long maps/invalid_maps/map_no_collectibles.ber

echo -e "\033[1;32m \n\ninvalid_char_on_the_map \033[0m"
./so_long maps/invalid_maps/invalid_char.ber

echo -e "\033[1;32m \n\nmap_no_exit \033[0m"
./so_long maps/invalid_maps/map_no_exit.ber

echo -e "\033[1;32m \n\nmap_no_player \033[0m"
./so_long maps/invalid_maps/map_no_player.ber

echo -e "\033[1;32m \n\nmap_wrong_size_line \033[0m"
./so_long maps/invalid_maps/map_wrong_size_line.ber

echo -e "\033[1;32m \n\nnot_closed \033[0m"
./so_long maps/invalid_maps/not_closed.ber

echo -e "\033[1;32m \n\nsquare_map \033[0m"
./so_long maps/invalid_maps/square_map.ber

chmod 222 ./maps/invalid_maps/write_only_file.ber
echo -e "\033[1;32m \n\nno_read_permissions \033[0m"
./so_long maps/invalid_maps/write_only_file.ber

echo -e "\033[1;32m \n\nmap_not_called_map.ber \033[0m"
./so_long maps/invalid_maps/invalid_name.bar
