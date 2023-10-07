const char* status_condition(int index)
{
	const char* status_condition_list[17];
	
	status_condition_list[0] = "None";
	status_condition_list[1] = "Asleep";
	status_condition_list[2] = "Poisoned";
	status_condition_list[4] = "Burned";
	status_condition_list[8] = "Frozen";
	status_condition_list[16] = "Paralyzed";

	return status_condition_list[index>>2];
}


const char* type(int index)
{
	const char* type_list[27];

	type_list[0] = "Normal";
	type_list[1] = "Fighting";
	type_list[2] = "Flying";
	type_list[3] = "Poison";
	type_list[4] = "Ground";
	type_list[5] = "Rock";
	type_list[7] = "Bug";
	type_list[8] = "Ghost";
	type_list[20] = "Fire";
	type_list[21] = "Water";
	type_list[22] = "Grass";
	type_list[23] = "Electric";
	type_list[24] = "Psychic";
	type_list[25] = "Ice";
	type_list[26] = "Dragon";
	
	return type_list[index];
}


const char* move_name(int index)
{
	const char* move_list[] =
	{
		"None",
		"Pound",
		"Karate Chop",
		"Double Slap",
		"Comet Punch",
		"Mega Punch",
		"Pay Day",
		"Fire Punch",
		"Ice Punch",
		"Thunder Punch",
		"Scratch",
		"Vise Grip",
		"Guillotine",
		"Razor Wind",
		"Swords Dance",
		"Cut",
		"Gust",
		"Wing Attack",
		"Whirlwind",
		"Fly",
		"Bind",
		"Slam",
		"Vine Whip",
		"Stomp",
		"Double Kick",
		"Mega Kick",
		"Jump Kick",
		"Rolling Kick",
		"Sand Attack",
		"Headbutt",
		"Horn Attack",
		"Fury Attack",
		"Horn Drill",
		"Tackle",
		"Body Slam",
		"Wrap",
		"Take Down",
		"Thrash",
		"Double-Edge",
		"Tail Whip",
		"Poison Sting",
		"Twineedle",
		"Pin Missile",
		"Leer",
		"Bite",
		"Growl",
		"Roar",
		"Sing",
		"Supersonic",
		"Sonic Boom",
		"Disable",
		"Acid",
		"Ember",
		"Flamethrower",
		"Mist",
		"Water Gun",
		"Hydro Pump",
		"Surf",
		"Ice Beam",
		"Blizzard",
		"Psybeam",
		"Bubble Beam",
		"Aurora Beam",
		"Hyper Beam",
		"Peck",
		"Drill Peck",
		"Submission",
		"Low Kick",
		"Counter",
		"Seismic Toss",
		"Strength",
		"Absorb",
		"Mega Drain",
		"Leech Seed",
		"Growth",
		"Razor Leaf",
		"Solar Beam",
		"Poison Powder",
		"Stun Spore",
		"Sleep Powder",
		"Petal Dance",
		"String Shot",
		"Dragon Rage",
		"Fire Spin",
		"Thunder Shock",
		"Thunderbolt",
		"Thunder Wave",
		"Thunder",
		"Rock Throw",
		"Earthquake",
		"Fissure",
		"Dig",
		"Toxic",
		"Confusion",
		"Psychic",
		"Hypnosis",
		"Meditate",
		"Agility",
		"Quick Attack",
		"Rage",
		"Teleport",
		"Night Shade",
		"Mimic",
		"Screech",
		"Double Team",
		"Recover",
		"Harden",
		"Minimize",
		"Smokescreen",
		"Confuse Ray",
		"Withdraw",
		"Defense Curl",
		"Barrier",
		"Light Screen",
		"Haze",
		"Reflect",
		"Focus Energy",
		"Bide",
		"Metronome",
		"Mirror Move",
		"Self-Destruct",
		"Egg Bomb",
		"Lick",
		"Smog",
		"Sludge",
		"Bone Club",
		"Fire Blast",
		"Waterfall",
		"Clamp",
		"Swift",
		"Skull Bash",
		"Spike Cannon",
		"Constrict",
		"Amnesia",
		"Kinesis",
		"Soft-Boiled",
		"High Jump Kick",
		"Glare",
		"Dream Eater",
		"Poison Gas",
		"Barrage",
		"Leech Life",
		"Lovely Kiss",
		"Sky Attack",
		"Transform",
		"Bubble",
		"Dizzy Punch",
		"Spore",
		"Flash",
		"Psywave",
		"Splash",
		"Acid Armor",
		"Crabhammer",
		"Explosion",
		"Fury Swipes",
		"Bonemerang",
		"Rest",
		"Rock Slide",
		"Hyper Fang",
		"Sharpen",
		"Conversion",
		"Tri Attack",
		"Super Fang",
		"Slash",
		"Substitute",
		"Struggle",
		"Sketch",	//Gen 2
		"Triple Kick",
		"Thief",
		"Spider Web",
		"Mind Reader",
		"Nightmare",
		"Flame Wheel",
		"Snore",
		"Curse",
		"Flail",
		"Conversion 2",
		"Aeroblast",
		"Cotton Spore",
		"Reversal",
		"Spite",
		"Powder Snow",
		"Protect",
		"Mach Punch",
		"Scary Face",
		"Feint Attack",
		"Sweet Kiss",
		"Belly Drum",
		"Sludge Bomb",
		"Mud-Slap",
		"Octazooka",
		"Spikes",
		"Zap Cannon",
		"Foresight",
		"Destiny Bond",
		"Perish Song",
		"Icy Wind",
		"Detect",
		"Bone Rush",
		"Lock-On",
		"Outrage",
		"Sandstorm",
		"Giga Drain",
		"Endure",
		"Charm",
		"Rollout",
		"False Swipe",
		"Swagger",
		"Milk Drink",
		"Spark",
		"Fury Cutter",
		"Steel Wing",
		"Mean Look",
		"Attract",
		"Sleep Talk",
		"Heal Bell",
		"Return",
		"Present",
		"Frustration",
		"Safeguard",
		"Pain Split",
		"Sacred Fire",
		"Magnitude",
		"Dynamic Punch",
		"Megahorn",
		"Dragon Breath",
		"Baton Pass",
		"Encore",
		"Pursuit",
		"Rapid Spin",
		"Sweet Scent",
		"Iron Tail",
		"Metal Claw",
		"Vital Throw",
		"Morning Sun",
		"Synthesis",
		"Moonlight",
		"Hidden Power",
		"Cross Chop",
		"Twister",
		"Rain Dance",
		"Sunny Day",
		"Crunch",
		"Mirror Coat",
		"Psych Up",
		"Extreme Speed",
		"Ancient Power",
		"Shadow Ball",
		"Future Sight",
		"Rock Smash",
		"Whirlpool",
		"Beat Up"
	};

	return move_list[index];
}


const char* species(int index)
{
	const char* species_list[] =
	{
		"None",
		"Bulbasaur",
		"Ivysaur",
		"Venusaur",
		"Charmander",
		"Charmeleon",
		"Charizard",
		"Squirtle",
		"Wartortle",
		"Blastoise",
		"Caterpie",
		"Metapod",
		"Butterfree",
		"Weedle",
		"Kakuna",
		"Beedrill",
		"Pidgey",
		"Pidgeotto",
		"Pidgeot",
		"Rattata",
		"Raticate",
		"Spearow",
		"Fearow",
		"Ekans",
		"Arbok",
		"Pikachu",
		"Raichu",
		"Sandshrew",
		"Sandslash",
		"Nidoran♀",
		"Nidorina",
		"Nidoqueen",
		"Nidoran♂",
		"Nidorino",
		"Nidoking",
		"Clefairy",
		"Clefable",
		"Vulpix",
		"Ninetales",
		"Jigglypuff",
		"Wigglytuff",
		"Zubat",
		"Golbat",
		"Oddish",
		"Gloom",
		"Vileplume",
		"Paras",
		"Parasect",
		"Venonat",
		"Venomoth",
		"Diglett",
		"Dugtrio",
		"Meowth",
		"Persian",
		"Psyduck",
		"Golduck",
		"Mankey",
		"Primeape",
		"Growlithe",
		"Arcanine",
		"Poliwag",
		"Poliwhirl",
		"Poliwrath",
		"Abra",
		"Kadabra",
		"Alakazam",
		"Machop",
		"Machoke",
		"Machamp",
		"Bellsprout",
		"Weepinbell",
		"Victreebel",
		"Tentacool",
		"Tentacruel",
		"Geodude",
		"Graveler",
		"Golem",
		"Ponyta",
		"Rapidash",
		"Slowpoke",
		"Slowbro",
		"Magnemite",
		"Magneton",
		"Farfetch'd",
		"Doduo",
		"Dodrio",
		"Seel",
		"Dewgong",
		"Grimer",
		"Muk",
		"Shellder",
		"Cloyster",
		"Gastly",
		"Haunter",
		"Gengar",
		"Onix",
		"Drowzee",
		"Hypno",
		"Krabby",
		"Kingler",
		"Voltorb",
		"Electrode",
		"Exeggcute",
		"Exeggutor",
		"Cubone",
		"Marowak",
		"Hitmonlee",
		"Hitmonchan",
		"Lickitung",
		"Koffing",
		"Weezing",
		"Rhyhorn",
		"Rhydon",
		"Chansey",
		"Tangela",
		"Kangaskhan",
		"Horsea",
		"Seadra",
		"Goldeen",
		"Seaking",
		"Staryu",
		"Starmie",
		"Mr. Mime",
		"Scyther",
		"Jynx",
		"Electabuzz",
		"Magmar",
		"Pinsir",
		"Tauros",
		"Magikarp",
		"Gyarados",
		"Lapras",
		"Ditto",
		"Eevee",
		"Vaporeon",
		"Jolteon",
		"Flareon",
		"Porygon",
		"Omanyte",
		"Omastar",
		"Kabuto",
		"Kabutops",
		"Aerodactyl",
		"Snorlax",
		"Articuno",
		"Zapdos",
		"Moltres",
		"Dratini",
		"Dragonair",
		"Dragonite",
		"Mewtwo",
		"Mew",
		"Chikorita",
		"Bayleef",
		"Meganium",
		"Cyndaquil",
		"Quilava",
		"Typhlosion",
		"Totodile",
		"Croconaw",
		"Feraligatr",
		"Sentret",
		"Furret",
		"Hoothoot",
		"Noctowl",
		"Ledyba",
		"Ledian",
		"Spinarak",
		"Ariados",
		"Crobat",
		"Chinchou",
		"Lanturn",
		"Pichu",
		"Cleffa",
		"Igglybuff",
		"Togepi",
		"Togetic",
		"Natu",
		"Xatu",
		"Mareep",
		"Flaaffy",
		"Ampharos",
		"Bellossom",
		"Marill",
		"Azumarill",
		"Sudowoodo",
		"Politoed",
		"Hoppip",
		"Skiploom",
		"Jumpluff",
		"Aipom",
		"Sunkern",
		"Sunflora",
		"Yanma",
		"Wooper",
		"Quagsire",
		"Espeon",
		"Umbreon",
		"Murkrow",
		"Slowking",
		"Misdreavus",
		"Unown",
		"Wobbuffet",
		"Girafarig",
		"Pineco",
		"Forretress",
		"Dunsparce",
		"Gligar",
		"Steelix",
		"Snubbull",
		"Granbull",
		"Qwilfish",
		"Scizor",
		"Shuckle",
		"Heracross",
		"Sneasel",
		"Teddiursa",
		"Ursaring",
		"Slugma",
		"Magcargo",
		"Swinub",
		"Piloswine",
		"Corsola",
		"Remoraid",
		"Octillery",
		"Delibird",
		"Mantine",
		"Skarmory",
		"Houndour",
		"Houndoom",
		"Kingdra",
		"Phanpy",
		"Donphan",
		"Porygon2",
		"Stantler",
		"Smeargle",
		"Tyrogue",
		"Hitmontop",
		"Smoochum",
		"Elekid",
		"Magby",
		"Miltank",
		"Blissey",
		"Raikou",
		"Entei",
		"Suicune",
		"Larvitar",
		"Pupitar",
		"Tyranitar",
		"Lugia",
		"Ho-oh",
		"Celebi"
	};

	return species_list[index];
}


const char gender_list(int index, int attack)
{
	//TODO: Add gen 2
	//Male		0
	//7:1		2
	//3:1		4
	//1:1		8
	//1:3		12
	//Female	16
	// If atkiv < value then female otherwise male
	const int gender[] = 
	{
		-1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 
		8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
		8, 8, 8, 8, 8, 8, 8, 8, 8, 16,
		16, 16, 0, 0, 0, 12, 12, 12, 12, 12,
		12, 8, 8, 8, 8, 8, 8, 8, 8, 8,
		8, 8, 8, 8, 8, 8, 8, 8, 4, 4,
		8, 8, 8, 4, 4, 4, 4, 4, 4, 8,
		8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
		8, -1, -1, 8, 8, 8, 8, 8, 8, 8,
		8, 8, 8, 8, 8, 8, 8, 8, 8, 8,

		-1, -1, 8, 8, 8, 8, 0, 0, 8, 8,
		8, 8, 8, 16, 8, 16, 8, 8, 8, 8,
		-1, -1, 8, 8, 16, 4, 4, 8, 0, 8,
		8, 8, -1, 2, 2, 2, 2, -1, 2, 2,
		2, 2, 2, 2, -1, -1, -1, 8, 8, 8,
		-1, -1

	};
	if(gender[index] == -1)
	{
		return 'x';
	}
	else if(attack < gender[index])
	{
		return 'f';
	}
	return 'm';
}


const char pk1_character_map(int index)
{
	//TODO: Characters in other languages and extend english characrers
	const char characters[] = 
	{
		' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '(', ')', ':', ';', '[', ']',
		'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
	};
	if(index < 0x7f)
	{
		return '\0';
	}
	return characters[index - 0x7F];
}


const int pk1_pk2_species(int index)
{
	//Convert Gen 1 and 2 internal Pokemon index to national pokedex number
	const int species_index[] = {0x00, 0x70, 0x73, 0x20, 0x23, 0x15, 0x64, 0x22, 0x50, 0x02, 0x67, 0x6C, 0x66, 0x58, 0x5E, 0x1D, 0x1F, 0x68, 0x6F, 0x83, 0x3B, 0x97, 0x82, 0x5A, 0x48, 0x5C, 0x7B, 0x78, 0x09, 0x7F, 0x72, 0x00, 0x00, 0x3A, 0x5F, 0x16, 0x10, 0x4F, 0x40, 0x4B, 0x71, 0x43, 0x7A, 0x6A, 0x6B, 0x18, 0x2F, 0x36, 0x60, 0x4C, 0x00, 0x7E, 0x00, 0x7D, 0x52, 0x6D, 0x00, 0x38, 0x56, 0x32, 0x80, 0x00, 0x00, 0x00, 0x53, 0x30, 0x95, 0x00, 0x00, 0x00, 0x54, 0x3C, 0x7C, 0x92, 0x90, 0x91, 0x84, 0x34, 0x62, 0x00, 0x00, 0x00, 0x25, 0x26, 0x19, 0x1A, 0x00, 0x00, 0x93, 0x94, 0x8C, 0x8D, 0x74, 0x75, 0x00, 0x00, 0x1B, 0x1C, 0x8A, 0x8B, 0x27, 0x28, 0x85, 0x88, 0x87, 0x86, 0x42, 0x29, 0x17, 0x2E, 0x3D, 0x3E, 0x0D, 0x0E, 0x0F, 0x00, 0x55, 0x39, 0x33, 0x31, 0x57, 0x00, 0x00, 0x0A, 0x0B, 0x0C, 0x44, 0x00, 0x37, 0x61, 0x2A, 0x96, 0x8F, 0x81, 0x00, 0x00, 0x59, 0x00, 0x63, 0x5B, 0x00, 0x65, 0x24, 0x6E, 0x35, 0x69, 0x00, 0x5D, 0x3F, 0x41, 0x11, 0x12, 0x79, 0x01, 0x03, 0x49, 0x00, 0x76, 0x77, 0x00, 0x00, 0x00, 0x00, 0x4D, 0x4E, 0x13, 0x14, 0x21, 0x1E, 0x4A, 0x89, 0x8E, 0x00, 0x51, 0x00, 0x00, 0x04, 0x07, 0x05, 0x08, 0x06, 0x00, 0x00, 0x00, 0x00, 0x2B, 0x2C, 0x2D, 0x45, 0x46, 0x47};

	return species_index[index];
}
