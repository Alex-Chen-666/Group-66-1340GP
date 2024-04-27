FLAGS = -pedantic-errors -std=c++17 -g
spider.o: spider.cpp spider.h rule.h printcard.h updownchoice.h column_center_print.h move.h new_game.h choose_mode.h deal.h stalemate3.h remove_complete_deck.h game_process.h finish.h choose_history.h process_record.h print_history.h loading_save.h full_screen.h
	g++ $(FLAGS) -c $<
full_screen.o: full_screen.cpp full_screen.h column_center_print.h
	g++ $(FLAGS) -c $<
rule.o: rule.cpp rule.h
	g++ $(FLAGS) -c $<
printcard.o: printcard.cpp printcard.h global.h column_center_print.h
	g++ $(FLAGS) -c $<
updownchoice.o: updownchoice.cpp updownchoice.h global.h column_center_print.h
	g++ $(FLAGS) -c $<
column_center_print.o: column_center_print.cpp column_center_print.h
	g++ $(FLAGS) -c $<
move.o: move.cpp move.h printcard.h
	g++ $(FLAGS) -c $<
animation.o: animation.cpp column_center_print.h animation.h
	g++ $(FLAGS) -c $<
deal.o: deal.cpp deal.h printcard.h
	g++ $(FLAGS) -c $<
new_game.o: new_game.cpp new_game.h updownchoice.h printcard.h
	g++ $(FLAGS) -c $<
choose_mode.o: choose_mode.cpp choose_mode.h updownchoice.h
	g++ $(FLAGS) -c $<
choose_game.o: choose_game.cpp choose_game.h updownchoice.h
	g++ $(FLAGS) -c $<
choose_history.o: choose_history.cpp choose_history.h updownchoice.h loading_save.h
	g++ $(FLAGS) -c $<
stalemate3.o: stalemate3.cpp stalemate3.h move.h rule.h
	g++ $(FLAGS) -c $<
finish.o: finish.cpp finish.h
	g++ $(FLAGS) -c $<
print_history.o: print_history.cpp print_history.h printcard.h loading_save.h
	g++ $(FLAGS) -c $<
process_record.o: process_record.cpp process_record.h 
	g++ $(FLAGS) -c $<
instruction.o: instruction.cpp instruction.h 
	g++ $(FLAGS) -c $<
loading_save.o: loading_save.cpp loading_save.h column_center_print.h
	g++ $(FLAGS) -c $<
remove_complete_deck.o: remove_complete_deck.cpp remove_complete_deck.h printcard.h
	g++ $(FLAGS) -c $<
game_process.o: game_process.cpp game_process.h rule.h printcard.h column_center_print.h move.h deal.h remove_complete_deck.h stalemate3.h finish.h loading_save.h
	g++ $(FLAGS) -c $<
print_grid.o: print_grid.cpp print_grid.h headfiles.h 
	g++ $(FLAGS)  -c $<
main_logic.o: main_logic.cpp main_logic.h headfiles.h
	g++ $(FLAGS)  -c $<
input_position.o: input_position.cpp input_position.h print_grid.h headfiles.h
	g++ $(FLAGS)  -c $<
choose_mode2.o: choose_mode2.cpp choose_mode2.h 
	g++  -pedantic-errors -std=c++17 -g -c $<
quick_game.o: quick_game.cpp quick_game.h print_grid.h main_logic.h input_position.h full_screen.h
	g++ $(FLAGS)  -c $<
instruction2.o: instruction2.cpp instruction2.h headfiles.h
	g++ $(FLAGS)  -c $<
end_animation.o: end_animation.cpp end_animation.h headfiles.h
	g++ $(FLAGS)  -c $<
poker_crush.o: poker_crush.cpp choose_mode2.h quick_game.cpp quick_game.h print_grid.h main_logic.h input_position.h full_screen.h instruction2.h end_animation.h
	g++ $(FLAGS)  -c $<
p: choose_mode2.o print_grid.o main_logic.o input_position.o animation.o quick_game.o instruction2.o end_animation.o poker_crush.o spider.o rule.o printcard.o updownchoice.o column_center_print.o move.o new_game.o choose_mode.o deal.o remove_complete_deck.o stalemate3.o game_process.o finish.o choose_history.o process_record.o print_history.o loading_save.o instruction.o full_screen.o choose_game.o main.cpp 
	g++ $(FLAGS)  -o $@ $^ -pthread
clean:
	rm  print_grid.o main_logic.o input_position.o quick_game.o instruction2.o end_animation.o poker_crush.o  rule.o printcard.o end_animation.o updownchoice.o column_center_print.o move.o new_game.o choose_mode.o deal.o remove_complete_deck.o stalemate3.o game_process.o choose_history.o process_record.o print_history.o loading_save.o instruction.o full_screen.o choose_game.o finish.o  spider.o choose_mode2.o animation.o
.PHONY: clean
