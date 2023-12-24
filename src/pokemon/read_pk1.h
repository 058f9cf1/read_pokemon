#ifndef READ_PK1_H
#define READ_PK1_H

typedef struct
{
	int hp;
	int attack;
	int defence;
	int speed;
	int special;
} stats;

typedef struct
{
	int name;
	int pp;
	int pp_ups;
} move;

typedef struct
{
	int species;
	int type_1;
	int type_2;
	int ot_id;
	int level;
	int exp_points;
	int current_hp;
	int status_condition;

	stats iv;
	stats ev;
	stats stat;

	move move_1;
	move move_2;
	move move_3;
	move move_4;

	int catch_rate;
	int original_trainer[10];
	int nickname[10];

	char gender;
	int shiny;
} gen_1_pokemon;

void read_pk1(gen_1_pokemon*, unsigned char*);

#endif
