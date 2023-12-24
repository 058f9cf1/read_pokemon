#include <stdio.h>

#include "pokemon_structs.h"
#include "tables.h"


void print_pk1(gen_1_pokemon* p, unsigned char* data)
{
	//Print out Pokemon data
	printf("Species: %s\n", species(pk1_pk2_species(p->species)));
	printf("Nickname: ");
	for(int i = 0; i < 10; i++)
	{
		printf("%c", pk1_character_map(p->nickname[i]));
	}
	if(p->type_1 == p->type_2)
	{
		printf("\nType: %s\n", type(p->type_1));
	}
	else
	{
		printf("\nType: %s/%s\n", type(p->type_1), type(p->type_2));
	}
	printf("Original Trainer: ");
	for(int i = 0; i < 10; i++)
	{
		printf("%c", pk1_character_map(p->original_trainer[i]));
	}
	printf("\nOT ID: %d\n", p->ot_id);
	printf("Level: %d\n", p->level);
	printf("Exp Points: %d\n", p->exp_points);
	printf("Current HP: %d\n", p->current_hp);
	printf("Status Condition: %s\n", status_condition(p->status_condition));
	printf("Catch Rate: %d\n", p->catch_rate);

	printf("\n   Stat| IV |    EV | Total\n");
	printf("-------|----|-------|------\n");
	printf("     HP|%3d |%6d |%5d\n", p->iv.hp, p->ev.hp, p->stat.hp);
	printf(" Attack|%3d |%6d |%5d\n", p->iv.attack, p->ev.attack, p->stat.attack);
	printf("Defence|%3d |%6d |%5d\n", p->iv.defence, p->ev.defence, p->stat.defence);
	printf("  Speed|%3d |%6d |%5d\n", p->iv.speed, p->ev.speed, p->stat.speed);
	printf("Special|%3d |%6d |%5d\n", p->iv.special, p->ev.special, p->stat.special);

	printf("\nMove 1: %s\n", move_name(p->move_1.name));
	printf("Move 2: %s\n", move_name(p->move_2.name));
	printf("Move 3: %s\n", move_name(p->move_3.name));
	printf("Move 4: %s\n", move_name(p->move_4.name));
	printf("Move 1 Current PP: %d\n", p->move_1.pp);
	printf("Move 1 PP Ups: %d\n", p->move_1.pp_ups);
	printf("Move 2 Current PP: %d\n", p->move_2.pp);
	printf("Move 2 PP Ups: %d\n", p->move_2.pp_ups);
	printf("Move 3 Current PP: %d\n", p->move_3.pp);
	printf("Move 3 PP Ups: %d\n", p->move_3.pp_ups);
	printf("Move 4 Current PP: %d\n", p->move_4.pp);
	printf("Move 4 PP Ups: %d\n", p->move_4.pp_ups);

	printf("\nGeneration 2 features\n");
	printf("Shiny: %d\n", p->shiny);
	printf("Gender: %c\n", p->gender);
	printf("Held Item: %s\n", catch_rate_to_item(p->catch_rate));
}
