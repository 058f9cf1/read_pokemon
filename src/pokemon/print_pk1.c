#include <stdio.h>

#include "data/pokemon_structs.h"
#include "data/tables.h"


int str_len(const char *s)
{
	int len = 0;

	while(*s++ && len < 10)
	{
		len++;
	}
	return len;
}


void print_main(pk1 *p)
{
	printf("|------------------------------------|\n");
	printf("| %.10s", p->nickname);
	if(p->gender == 'm')
	{
		printf("♂");
	}
	else if(p->gender == 'f')
	{
		printf("♀");
	}
	if(p->shiny)
	{
		printf("*");
	}
	else
	{
		printf(" ");
	}
	if(p->gender == 'x')
	{
		printf(" ");
	}
	printf("%*s", 27 - str_len(p->nickname) - str_len(species(gb_species_index(p->species))), "");
	printf("#%03d %s |\n", gb_species_index(p->species), species(gb_species_index(p->species)));

	printf("| L%-3d", p->level);
	printf("%*s", 29 - str_len(type(p->type_1)) - str_len(type(p->type_2)), "");
	if(p->type_1 == p->type_2)
	{
		printf("%*s", str_len(type(p->type_1)) + 1, "");
		printf("%s |\n", type(p->type_1));
	}
	else
	{
		printf("%s/%s |\n", type(p->type_1), type(p->type_2));
	}

	printf("| %s/%05d", p->original_trainer, p->ot_id);
	printf("%*s |\n", 28 - str_len(p->original_trainer), "");
	printf("|------------------------------------|\n");
}


void print_extra(pk1 *p)
{
	printf("| HP: %3d/%-3d STATUS/%-15s |\n", p->current_hp, p->stat.hp, status_condition(p->status_condition));
	printf("| Experience Points: %-14d  |\n", p->exp_points);
	printf("| Held Item: %-23s |\n", catch_rate_to_item(p->catch_rate));
	printf("|------------------------------------|\n");
}


void print_stats(pk1 *p)
{
	printf("|-----------|----|-------|--------|\n");
	printf("|    Stat   | IV |   EV  |  Total |\n");
	printf("|-----------|----|-------|--------|\n");
	printf("|       HP  |%3d |%6d |%6d  |\n", p->iv.hp, p->ev.hp, p->stat.hp);
	printf("|   Attack  |%3d |%6d |%6d  |\n", p->iv.attack, p->ev.attack, p->stat.attack);
	printf("|  Defence  |%3d |%6d |%6d  |\n", p->iv.defence, p->ev.defence, p->stat.defence);
	printf("|    Speed  |%3d |%6d |%6d  |\n", p->iv.speed, p->ev.speed, p->stat.speed);
	printf("|  Special  |%3d |%6d |%6d  |\n", p->iv.special, p->ev.special, p->stat.special);
	printf("|-----------|----|-------|--------|\n");
}


void print_moves(pk1 *p)
{
	printf("|----------------|----------------|\n");
	printf("| %-14s | %-14s |\n", move_name(p->move_1.name), move_name(p->move_2.name));
	printf("|                |                |\n");
	printf("| %10d(+%d) | %10d(+%d) |\n", p->move_1.pp, p->move_1.pp_ups, p->move_2.pp, p->move_2.pp_ups);
	printf("|----------------|----------------|\n");
	printf("| %-14s | %-14s |\n", move_name(p->move_3.name), move_name(p->move_4.name));
	printf("|                |                |\n");
	printf("| %10d(+%d) | %10d(+%d) |\n", p->move_3.pp, p->move_3.pp_ups, p->move_4.pp, p->move_4.pp_ups);
	printf("|----------------|----------------|\n");
}


void print_pair(pk1 *p)
{
	printf("|-----------|----|-------|--------|");
	printf(" |----------------|----------------|\n");
	printf("|    Stat   | IV |   EV  |  Total |");
	printf(" | %-14s | %-14s |\n", move_name(p->move_1.name), move_name(p->move_2.name));
	printf("|-----------|----|-------|--------|");
	printf(" |                |                |\n");
	printf("|       HP  |%3d |%6d |%6d  |", p->iv.hp, p->ev.hp, p->stat.hp);
	printf(" | %10d(+%d) | %10d(+%d) |\n", p->move_1.pp, p->move_1.pp_ups, p->move_2.pp, p->move_2.pp_ups);

	printf("|   Attack  |%3d |%6d |%6d  |", p->iv.attack, p->ev.attack, p->stat.attack);
	printf(" |----------------|----------------|\n");
	printf("|  Defence  |%3d |%6d |%6d  |", p->iv.defence, p->ev.defence, p->stat.defence);
	printf(" | %-14s | %-14s |\n", move_name(p->move_3.name), move_name(p->move_4.name));
	printf("|    Speed  |%3d |%6d |%6d  |", p->iv.speed, p->ev.speed, p->stat.speed);
	printf(" |                |                |\n");
	printf("|  Special  |%3d |%6d |%6d  |", p->iv.special, p->ev.special, p->stat.special);
	printf(" | %10d(+%d) | %10d(+%d) |\n", p->move_3.pp, p->move_3.pp_ups, p->move_4.pp, p->move_4.pp_ups);
	printf("|-----------|----|-------|--------|");
	printf(" |----------------|----------------|\n");

}


void print_pk1(pk1 *p)
{
	print_main(p);
	print_extra(p);
	print_pair(p);
}
