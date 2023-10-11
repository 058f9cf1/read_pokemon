#include <stdio.h>

#include "tables.h"

typedef struct
{
	int hp;
	int attack;
	int defence;
	int speed;
	int special;
}stats;

typedef struct
{
	int name;
	int pp;
	int pp_ups;
}move;

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
}pokemon;


int read_pk1(unsigned char* data)
{
	pokemon p;
	//0, 1, 2
	p.species = data[3];
	p.current_hp = (data[4] << 8) | data[5];
	//6
	p.status_condition = data[7];
	p.type_1 = data[8];
	p.type_2 = data[9];
	p.catch_rate = data[10];
	p.move_1.name = data[11];
	p.move_2.name = data[12];
	p.move_3.name = data[13];
	p.move_4.name = data[14];
	p.ot_id = (data[15] << 8) | data[16];
	p.exp_points = (data[17] << 16) | (data[18] << 8) | data[19];
	p.ev.hp = (data[20] << 8) | data[21];
	p.ev.attack = (data[22] << 8) | data[23];
	p.ev.defence = (data[24] << 8) | data[25];
	p.ev.speed = (data[26] << 8) | data[27];
	p.ev.special = (data[28] << 8) | data[29];
	p.iv.attack = data[30] >> 4;
	p.iv.defence = data[30] & 0b1111;
	p.iv.speed = data[31] >> 4;
	p.iv.special = data[31] & 0b1111;
	p.move_1.pp = data[32] & 0b111111;
	p.move_1.pp_ups = data[32] >> 6;
	p.move_2.pp = data[33] & 0b111111;
	p.move_2.pp_ups = data[33] >> 6;
	p.move_3.pp = data[34] & 0b111111;
	p.move_3.pp_ups = data[34] >> 6;
	p.move_4.pp = data[35] & 0b111111;
	p.move_4.pp_ups = data[35] >> 6;
	p.level = data[36];
	p.stat.hp = (data[37] << 8) | data[38];
	p.stat.attack = (data[39] << 8) | data[40];
	p.stat.defence = (data[41] << 8) | data[42];
	p.stat.speed = (data[43] << 8) | data[44];
	p.stat.special = (data[45] << 8) | data[46];

	for(int i = 0; i < 10; i++)
	{
		p.original_trainer[i] = data[47 + i];
		p.nickname[i] = data[58 + i];
	}

	p.iv.hp = ((p.iv.attack & 1) << 3) + ((p.iv.defence & 1) << 2) + ((p.iv.speed & 1) << 1) + (p.iv.special & 1);
	p.gender = gender_list(pk1_pk2_species(p.species), p.iv.attack);
	p.shiny = 0;
	if(p.iv.defence == 10 && p.iv.speed == 10 && p.iv.special == 10)
	{
		if((p.iv.attack & 0b11) == 0b10 || (p.iv.attack & 0b11) == 0b11)
		{
			p.shiny = 1;
		}

	}


	//Print out Pokemon data
	printf("Species: %s\n", species(pk1_pk2_species(p.species)));
	printf("Nickname: ");
	for(int i = 0; i < 10; i++)
	{
		printf("%c", pk1_character_map(p.nickname[i]));
	}
	if(p.type_1 == p.type_2)
	{
		printf("\nType: %s\n", type(p.type_1));
	}
	else
	{
		printf("\nType: %s/%s\n", type(p.type_1), type(p.type_2));
	}
	printf("Original Trainer: ");
	for(int i = 0; i < 10; i++)
	{
		printf("%c", pk1_character_map(p.original_trainer[i]));
	}
	printf("\nOT ID: %d\n", p.ot_id);
	printf("Level: %d\n", p.level);
	printf("Exp Points: %d\n", p.exp_points);
	printf("Current HP: %d\n", p.current_hp);
	printf("Status Condition: %s\n", status_condition(p.status_condition));
	printf("Catch Rate: %d\n", p.catch_rate);

	printf("\n   Stat| IV |    EV | Total\n");
	printf("-------|----|-------|------\n");
	printf("     HP|%3d |%6d |%5d\n", p.iv.hp, p.ev.hp, p.stat.hp);
	printf(" Attack|%3d |%6d |%5d\n", p.iv.attack, p.ev.attack, p.stat.attack);
	printf("Defence|%3d |%6d |%5d\n", p.iv.defence, p.ev.defence, p.stat.defence);
	printf("  Speed|%3d |%6d |%5d\n", p.iv.speed, p.ev.speed, p.stat.speed);
	printf("Special|%3d |%6d |%5d\n", p.iv.special, p.ev.special, p.stat.special);
	
	printf("\nMove 1: %s\n", move_name(p.move_1.name));
	printf("Move 2: %s\n", move_name(p.move_2.name));
	printf("Move 3: %s\n", move_name(p.move_3.name));
	printf("Move 4: %s\n", move_name(p.move_4.name));
	printf("Move 1 Current PP: %d\n", p.move_1.pp);
	printf("Move 1 PP Ups: %d\n", p.move_1.pp_ups);
	printf("Move 2 Current PP: %d\n", p.move_2.pp);
	printf("Move 2 PP Ups: %d\n", p.move_2.pp_ups);
	printf("Move 3 Current PP: %d\n", p.move_3.pp);
	printf("Move 3 PP Ups: %d\n", p.move_3.pp_ups);
	printf("Move 4 Current PP: %d\n", p.move_4.pp);
	printf("Move 4 PP Ups: %d\n", p.move_4.pp_ups);

	printf("\nGeneration 2 features\n");
	printf("Shiny: %d\n", p.shiny);
	printf("Gender: %c\n", p.gender);
	printf("Held Item: %d\n", catch_rate_to_item(p.catch_rate));

	return 0;
}
