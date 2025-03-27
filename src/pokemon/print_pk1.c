#include <stdio.h>

#include "data/pokemon_structs.h"
#include "data/tables.h"


void print_pk1(pk1 *p)
{
	//Print out Pokemon data
	printf("\n|------------------------------------|\n");
	printf("| #%03d %-10s  ", gb_species_index(p->species), species(gb_species_index(p->species)));
	if(p->type_1 == p->type_2)
	{
		printf("%17s |\n", type(p->type_1));
	}
	else
	{
		printf("%8s/%-8s |\n", type(p->type_1), type(p->type_2));
	}
	printf("| %-10s %-22c", p->nickname, p->gender);
	if(p->shiny)
	{
		printf("*");
	}
	else
	{
		printf(" ");
	}
	printf(" |\n| OT: %-10s TID: %05d          |\n", p->original_trainer, p->ot_id);
	printf("| Level %-3d Exp %-20d |\n", p->level, p->exp_points);
	printf("| HP: %3d/%-3d Status: %-14s |\n", p->current_hp, p->stat.hp, status_condition(p->status_condition));
	printf("| Held Item: %-23s |\n", catch_rate_to_item(p->catch_rate));
	printf("|------------------------------------|\n");

	printf("\n|-----------|----|-------|--------|\n");
	printf("|    Stat   | IV |    EV | Total  |\n");
	printf("|-----------|----|-------|--------|\n");
	printf("|       HP  |%3d |%6d |%6d  |\n", p->iv.hp, p->ev.hp, p->stat.hp);
	printf("|   Attack  |%3d |%6d |%6d  |\n", p->iv.attack, p->ev.attack, p->stat.attack);
	printf("|  Defence  |%3d |%6d |%6d  |\n", p->iv.defence, p->ev.defence, p->stat.defence);
	printf("|    Speed  |%3d |%6d |%6d  |\n", p->iv.speed, p->ev.speed, p->stat.speed);
	printf("|  Special  |%3d |%6d |%6d  |\n", p->iv.special, p->ev.special, p->stat.special);
	printf("|-----------|----|-------|--------|\n");

	printf("\n|----------------|----------------|\n");
	printf("| %-14s | %-14s |\n", move_name(p->move_1.name), move_name(p->move_2.name));
	printf("|                |                |\n");
	printf("| %10d(+%d) | %10d(+%d) |\n", p->move_1.pp, p->move_1.pp_ups, p->move_2.pp, p->move_2.pp_ups);
	printf("|----------------|----------------|\n");
	printf("| %-14s | %-14s |\n", move_name(p->move_3.name), move_name(p->move_4.name));
	printf("|                |                |\n");
	printf("| %10d(+%d) | %10d(+%d) |\n", p->move_3.pp, p->move_3.pp_ups, p->move_4.pp, p->move_4.pp_ups);
	printf("|----------------|----------------|\n");
}
