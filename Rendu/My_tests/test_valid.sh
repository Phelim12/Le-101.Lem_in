echo "\n\n01for10\n\n"
valgrind --leak-check=full --show-leak-kinds=all ./lem-in < TEST_VALID/01for10
sleep 1
echo "\n\n02for10\n\n"
valgrind --leak-check=full --show-leak-kinds=all ./lem-in < TEST_VALID/02for10
sleep 1
echo "\n\n03for10\n\n"
valgrind --leak-check=full --show-leak-kinds=all ./lem-in < TEST_VALID/03for10
sleep 1
echo "\n\n04for10\n\n"
valgrind --leak-check=full --show-leak-kinds=all ./lem-in < TEST_VALID/04for10
sleep 1
echo "\n\n05for10\n\n"
valgrind --leak-check=full --show-leak-kinds=all ./lem-in < TEST_VALID/05for10
sleep 1
echo "\n\n06for10\n\n"
valgrind --leak-check=full --show-leak-kinds=all ./lem-in < TEST_VALID/06for10
sleep 1
echo "\n\n07for10\n\n"
valgrind --leak-check=full --show-leak-kinds=all ./lem-in < TEST_VALID/07for10
sleep 1
echo "\n\n08for10\n\n"
valgrind --leak-check=full --show-leak-kinds=all ./lem-in < TEST_VALID/08for10
sleep 1
echo "\n\n09for10\n\n"
valgrind --leak-check=full --show-leak-kinds=all ./lem-in < TEST_VALID/09for10
sleep 1
echo "\n\n1000_map\n\n"
valgrind --leak-check=full --show-leak-kinds=all ./lem-in < TEST_VALID/1000_map
sleep 1
echo "\n\n100_map\n\n"
valgrind --leak-check=full --show-leak-kinds=all ./lem-in < TEST_VALID/100_map
sleep 1
echo "\n\n100_map_0\n\n"
valgrind --leak-check=full --show-leak-kinds=all ./lem-in < TEST_VALID/100_map_0
sleep 1
echo "\n\n10for10\n\n"
valgrind --leak-check=full --show-leak-kinds=all ./lem-in < TEST_VALID/10for10
sleep 1
echo "\n\n200_map\n\n"
valgrind --leak-check=full --show-leak-kinds=all ./lem-in < TEST_VALID/200_map
sleep 1
echo "\n\n300_map\n\n"
valgrind --leak-check=full --show-leak-kinds=all ./lem-in < TEST_VALID/300_map
sleep 1
echo "\n\n400_map\n\n"
valgrind --leak-check=full --show-leak-kinds=all ./lem-in < TEST_VALID/400_map
sleep 1
echo "\n\n500_map\n\n"
valgrind --leak-check=full --show-leak-kinds=all ./lem-in < TEST_VALID/500_map
sleep 1
echo "\n\ncmd_after_ant\n\n"
valgrind --leak-check=full --show-leak-kinds=all ./lem-in < TEST_VALID/cmd_after_ant
sleep 1
echo "\n\ncmd_after_end\n\n"
valgrind --leak-check=full --show-leak-kinds=all ./lem-in < TEST_VALID/cmd_after_end
sleep 1
echo "\n\ncmd_after_pipes\n\n"
valgrind --leak-check=full --show-leak-kinds=all ./lem-in < TEST_VALID/cmd_after_pipes
sleep 1
echo "\n\ncmd_after_rooms\n\n"
valgrind --leak-check=full --show-leak-kinds=all ./lem-in < TEST_VALID/cmd_after_rooms
sleep 1
echo "\n\ncmd_after_start\n\n"
valgrind --leak-check=full --show-leak-kinds=all ./lem-in < TEST_VALID/cmd_after_start
sleep 1
echo "\n\ncmd_b_a_ant\n\n"
valgrind --leak-check=full --show-leak-kinds=all ./lem-in < TEST_VALID/cmd_b_a_ant
sleep 1
echo "\n\ncmd_b_a_pipes\n\n"
valgrind --leak-check=full --show-leak-kinds=all ./lem-in < TEST_VALID/cmd_b_a_pipes
sleep 1
echo "\n\ncmd_b_a_rooms\n\n"
valgrind --leak-check=full --show-leak-kinds=all ./lem-in < TEST_VALID/cmd_b_a_rooms
sleep 1
echo "\n\ncmd_before_ant\n\n"
valgrind --leak-check=full --show-leak-kinds=all ./lem-in < TEST_VALID/cmd_before_ant
sleep 1
echo "\n\ncmd_before_end\n\n"
valgrind --leak-check=full --show-leak-kinds=all ./lem-in < TEST_VALID/cmd_before_end
sleep 1
echo "\n\ncmd_before_pipes\n\n"
valgrind --leak-check=full --show-leak-kinds=all ./lem-in < TEST_VALID/cmd_before_pipes
sleep 1
echo "\n\ncmd_before_rooms\n\n"
valgrind --leak-check=full --show-leak-kinds=all ./lem-in < TEST_VALID/cmd_before_rooms
sleep 1
echo "\n\ncmd_before_start\n\n"
valgrind --leak-check=full --show-leak-kinds=all ./lem-in < TEST_VALID/cmd_before_start
sleep 1
echo "\n\ncmd_mass_pipes\n\n"
valgrind --leak-check=full --show-leak-kinds=all ./lem-in < TEST_VALID/cmd_mass_pipes
sleep 1
echo "\n\ncmd_mass_rooms\n\n"
valgrind --leak-check=full --show-leak-kinds=all ./lem-in < TEST_VALID/cmd_mass_rooms
sleep 1
echo "\n\ncomment_###\n\n"
valgrind --leak-check=full --show-leak-kinds=all ./lem-in < TEST_VALID/comment_###
sleep 1
echo "\n\ncomment_###2\n\n"
valgrind --leak-check=full --show-leak-kinds=all ./lem-in < TEST_VALID/comment_###2
sleep 1
echo "\n\ncomment_after_ant\n\n"
valgrind --leak-check=full --show-leak-kinds=all ./lem-in < TEST_VALID/comment_after_ant
sleep 1
echo "\n\ncomment_after_end\n\n"
valgrind --leak-check=full --show-leak-kinds=all ./lem-in < TEST_VALID/comment_after_end
sleep 1
echo "\n\ncomment_after_end2\n\n"
valgrind --leak-check=full --show-leak-kinds=all ./lem-in < TEST_VALID/comment_after_end2
sleep 1
echo "\n\ncomment_after_pipes\n\n"
valgrind --leak-check=full --show-leak-kinds=all ./lem-in < TEST_VALID/comment_after_pipes
sleep 1
echo "\n\ncomment_after_rooms\n\n"
valgrind --leak-check=full --show-leak-kinds=all ./lem-in < TEST_VALID/comment_after_rooms
sleep 1
echo "\n\ncomment_after_start\n\n"
valgrind --leak-check=full --show-leak-kinds=all ./lem-in < TEST_VALID/comment_after_start
sleep 1
echo "\n\ncomment_after_start2\n\n"
valgrind --leak-check=full --show-leak-kinds=all ./lem-in < TEST_VALID/comment_after_start2
sleep 1
echo "\n\ncomment_b_a_pipes\n\n"
valgrind --leak-check=full --show-leak-kinds=all ./lem-in < TEST_VALID/comment_b_a_pipes
sleep 1
echo "\n\ncomment_b_a_rooms\n\n"
valgrind --leak-check=full --show-leak-kinds=all ./lem-in < TEST_VALID/comment_b_a_rooms
sleep 1
echo "\n\ncomment_before_ant\n\n"
valgrind --leak-check=full --show-leak-kinds=all ./lem-in < TEST_VALID/comment_before_ant
sleep 1
echo "\n\ncomment_before_ant2\n\n"
valgrind --leak-check=full --show-leak-kinds=all ./lem-in < TEST_VALID/comment_before_ant2
sleep 1
echo "\n\ncomment_before_end\n\n"
valgrind --leak-check=full --show-leak-kinds=all ./lem-in < TEST_VALID/comment_before_end
sleep 1
echo "\n\ncomment_before_pipes\n\n"
valgrind --leak-check=full --show-leak-kinds=all ./lem-in < TEST_VALID/comment_before_pipes
sleep 1
echo "\n\ncomment_before_rooms\n\n"
valgrind --leak-check=full --show-leak-kinds=all ./lem-in < TEST_VALID/comment_before_rooms
sleep 1
echo "\n\ncomment_before_start\n\n"
valgrind --leak-check=full --show-leak-kinds=all ./lem-in < TEST_VALID/comment_before_start
sleep 1
echo "\n\ncomment_mass_pipes\n\n"
valgrind --leak-check=full --show-leak-kinds=all ./lem-in < TEST_VALID/comment_mass_pipes
sleep 1
echo "\n\ncomment_mass_rooms\n\n"
valgrind --leak-check=full --show-leak-kinds=all ./lem-in < TEST_VALID/comment_mass_rooms
sleep 1
echo "\n\ncomment_pipe\n\n"
valgrind --leak-check=full --show-leak-kinds=all ./lem-in < TEST_VALID/comment_pipe
sleep 1
echo "\n\ncomment_room\n\n"
valgrind --leak-check=full --show-leak-kinds=all ./lem-in < TEST_VALID/comment_room
sleep 1
echo "\n\nfour_ways\n\n"
valgrind --leak-check=full --show-leak-kinds=all ./lem-in < TEST_VALID/four_ways
sleep 1
echo "\n\nmap_6\n\n"
valgrind --leak-check=full --show-leak-kinds=all ./lem-in < TEST_VALID/map_6
sleep 1
echo "\n\nmap_test0\n\n"
valgrind --leak-check=full --show-leak-kinds=all ./lem-in < TEST_VALID/map_test0
sleep 1
echo "\n\nmap_test0\n\n"
valgrind --leak-check=full --show-leak-kinds=all ./lem-in < TEST_VALID/map_test2
sleep 1
echo "\n\nmap_test2\n\n"
valgrind --leak-check=full --show-leak-kinds=all ./lem-in < TEST_VALID/map_test2
sleep 1
echo "\n\nsubject0.map\n\n"
valgrind --leak-check=full --show-leak-kinds=all ./lem-in < TEST_VALID/subject0.map
sleep 1
echo "\n\nsubject1.map\n\n"
valgrind --leak-check=full --show-leak-kinds=all ./lem-in < TEST_VALID/subject1.map
sleep 1
echo "\n\nsubject2.map\n\n"
valgrind --leak-check=full --show-leak-kinds=all ./lem-in < TEST_VALID/subject2.map
sleep 1
echo "\n\nthree_ways\n\n"
valgrind --leak-check=full --show-leak-kinds=all ./lem-in < TEST_VALID/three_ways
sleep 1
echo "\n\ntwo_ways\n\n"
valgrind --leak-check=full --show-leak-kinds=all ./lem-in < TEST_VALID/two_ways
sleep 1
echo "\n\ntwo_ways_collision\n\n"
valgrind --leak-check=full --show-leak-kinds=all ./lem-in < TEST_VALID/two_ways_collision
sleep 1
echo "\n\ntwo_ways_long\n\n"
valgrind --leak-check=full --show-leak-kinds=all ./lem-in < TEST_VALID/two_ways_long
sleep 1
echo "\n\ntwo_ways_long\n\n"