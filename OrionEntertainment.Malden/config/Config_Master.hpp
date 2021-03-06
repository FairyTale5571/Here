#define true 1
#define false 0

/*
    Master settings for various features and functionality
*/
class Life_Settings {
/* Logging and Security Settings*/
    /* Security Settings */

    /* Debit Card Configuration */
    debit_tax = true;	//Tax a player when they have used a Debit card to purchase something? - This is mainly a money sink in case everyone on your server owns a debit card, as they'll never have money on their person (so they can't be robbed) if they do.
    debit_taxAmount = 0.15; // Tax the player pays when purchasing with a debit card. Tax = Price * debit_taxAmount. debit_tax must be true. Eg. - If an item is $45,000 and your tax is set to 0.15, amount paid after tax will be $51,750. (total tax paid $6750.)
    debit_price = 75000; // Price of purchasing a debit card from the bank.
    debit_weapons = true; // Allows the use of debit cards when purchasing/selling weapons.
    debit_clothing = true; // Allows the use of debit cards when purchasing/selling clothing.
    debit_vItems = true; // Allows the use of Debit Cards when purchasing/selling virtual items.
    debit_vehicles = true; // Allows the use of Debit Cards when purchasing/renting/selling vehicles.
    item_debit = true; // Enables/Disables virtual debit cards (life_inv_debitcard) that can be lost on player death.

    /* Auction House Settings */
    ah_listing_limit = 3; //Amount of listings per player
    ah_auctioneers[] = { auchouse, auchouse_1, auchouse_2 }; //Object var names of your auctioneers <--- make sure you make an npc and place name in this array
    ah_percent = 30; // Percentage of tax to pay when selling item.
    ah_time_to_expire = 5; //Time until the listing is expired. in days
    ah_time_to_delete = 1; //Time until the listing is deleted after expiration. in days


    /* Data Logging Settings */
    battlEye_friendlyLogging = false; //False [default] - Read the logs from the server.rpt. True - Read the logs from the publicVariable.log. NOTE: Due to how diag_log works it will log to both files either way and the setting is merely for beautification purposes.
    player_advancedLog = false; //False [default] - No advanced logging. True - Logs house purchase and sale, vehicle purchase, sale, and chop shopping, police arrests, and gang creations. Search for: advanced_log
    player_moneyLog = false; //False [default] - No money logging. True - Logs player bank deposits, withdraws, and transfers, gang bank deposits and withdraws, money picked up off of the ground, and player robbery. Search for: money_log
    player_deathLog = false; //False [default] - No death logging. True - Logs victim and killer, and vehicle or weapon if used, when a player dies. Search for: death_log

/* Database Related Settings */
    /* Player Data Saving */
    save_virtualItems = true; //Save Virtual items (all sides)?
    saved_virtualItems[] = { "knife", "bandages", "panicbutton", "mushrooms", "uraniumU", "uranium", "LSD", "pdrill", "fueldart", "dogwhistle", "head", "flashlight", "gpstracker", "tent1", "campfire", "gokart", "protest", "volleyball", "goldcoin", "pliers", "airhorn", "megaphone", "axe", "lumber", "timber", "barrel", "butt", "sight", "trigger", "engine", "plans", "beer", "whiskey", "moonshine", "pepsi", "cocaCola", "monsterEnergy", "doritos", "shittynoodles", "kfc", "easterEggs", "debitCard", "zipties", "blindfold", "codeCracker", "cprKit", "morphine", "keys", "handcuffs", "pickaxe","fuelEmpty","fuelFull", "spikeStrip", "lockpick", "defuseKit","redgull","coffee","waterBottle","apple","peach","tbacon","donuts","rabbit","salema","ornate","mackerel","tuna","mullet","catshark","turtle_soup","hen","rooster","sheep","goat","defibrillator","toolkit", "storagesmall", "storagebig", "furniturewoodtable","furnituretarget","furnitureportgen","furniturefmradio","furniturewoodblue","furnituremetalrack","furniturePalletVert","furnitureMapAltis","furnitureTentA","furnitureSunChairGreen","furnitureSunChair","furnitureSleepingBagBrown","furnitureSleepingBagBlue","furnitureSleepingBag","furniturecampingtable","furnitureopenlaptop","furniturebagshort","furniturechair","furnituredesk","furniturespotlight" }; //Array of virtual items that can be saved on your player.
    save_playerStats = true; //Save food, water and damage (all sides)?
    save_civilian_weapons = true; //Allow civilians to save weapons on them?
    save_civilian_position = true; //Save civilian location?
    save_civilian_position_restart = true; //Save civilian location only between restarts. 
    //^^^TURN TO TRUE BEFORE LAUNCH
    /* !!!TO SAVE POSITION BETWEEN RESTARTS save_civilian_position MUST BE TRUE!!! */
    save_civilian_positionStrict = false; //Strip the player if possible combat-log?  WARNING: Server crashes and lack of reliable syncing can trigger this.

    /* Vehicle Data Saving */
    save_vehicle_virtualItems = true; //Save virtual items inside the vehicle (all sides)(-- See defined items on next line --)
    save_vehicle_items[] = { "knife", "pdrill", "fueldart", "dogwhistle", "head", "flashlight", "gpstracker", "tent1", "campfire", "gokart", "protest", "volleyball", "goldcoin", "airhorn", "megaphone", "axe", "pepsi", "cocaCola", "monsterEnergy", "doritos", "shittynoodles", "kfc", "easterEggs", "debitCard", "zipties", "blindfold", "cprKit", "morphine", "keys", "handcuffs", "pickaxe","fuelEmpty","fuelFull", "spikeStrip", "lockpick", "defuseKit" };
    save_vehicle_inventory = true; //Save Arma inventory of vehicle to the database
    save_vehicle_fuel = false; //Save vehicle fuel level to the database (Impounded/Garaged).
    save_vehicle_damage = true; //Save vehicle damage to the database.
    save_vehicle_illegal = true; //This will allow cops to be advised when a vehicle, with illegal items in it, is impounded. This will also save illegal items as proof of crime, and needs "save_vehicle_virtualItems" set as true. Illegal items don't need to be set in save_vehicle_items[] for being saved, if it's enabled.

/*Cop Settings*/
    cop_cars[]= {"C_Offroad_01_F","B_MRAP_01_F","C_SUV_01_F","C_Hatchback_01_sport_F","B_Heli_Light_01_F","B_Heli_Transport_01_F","I_G_Offroad_01_F","C_Offroad_02_unarmed_F","B_T_LSV_01_unarmed_F","B_LSV_01_unarmed_F","B_CTRG_LSV_01_light_F"};


/* System Settings */
    /* ATM & Federal Reserve System Configurations */
    global_ATM = true; //Allow users to access any ATM on the map (Marked & Unmarked).
    noatm_timer = 15; //Time in minutes that players cannot deposit money after selling stolen gold.
    minimum_cops = 10; //!!!!!!change this before server launch
    minimum_cops_bank = 7; //New bank

    /*Death settings*/
    drop_weapons_onDeath = false; //Set true to enable weapon dropping on death. False (default) will delete player weapons on death, allowing them to be revived with them instead

    /* Lumber Related Settings */
    enable_lumbering = true;
    
    /* Basic System Configurations */
    donor_level = true; //Enable the donor level set in database (var = life_donorlevel; levels = 0,1,2,3,4,5). ATTENTION! Before enabling, read: https://www.bistudio.com/community/game-content-usage-rules & https://www.bistudio.com/monetization
    enable_fatigue = false; //Set to false to disable the ARMA 3 fatigue system.
    total_maxWeight = 34; //Static variable for the maximum weight allowed without having a backpack
    respawn_timer = 100; //How many seconds a player should wait, before being able to respawn. Minimum 5 seconds.

    /* Channel 7 News Station Configurations */
    news_broadcast_cost = 1000000; //Cost for a player to send a news station broadcast.
    news_broadcast_cooldown = 20; //Time in minutes that is required between news station broadcasts. (Default = 20 minutes)
    news_broadcast_header_length = 60; //Number of characters that a header can consist of. Anything over this may clip. This depends on the font size and various other factors. Adjust with caution.
	
	//bank_cooldown = 1; //
	
    /* Clothing System Configurations */
    civ_skins = false; //Enable or disable civilian skins. Before enabling, you must add all the SEVEN files to textures folder. (It must be named as: civilian_uniform_1.jpg, civilian_uniform_2.jpg...civilian_uniform_6.jpg, civilian_uniform_7.jpg)
    cop_extendedSkins = false; //Enable or disable cop skins by level. Before enabling, you must add all the EIGHT files to textures folder. (It must be named as: cop_uniform.jpg + cop_uniform_1.jpg, cop_uniform_2.jpg...cop_uniform_6.jpg, cop_uniform_7.jpg; meaning cop_uniform = life_coplevel=0, cop_uniform_1 = life_coplevel=1, cop_uniform_2 = life_coplevel=2, etc...)
    clothing_noTP = true;  //Disable clothing preview teleport? (true = no teleport. false = teleport)
    clothing_box = false; //true = teleport to a black box. false = teleport to somewhere on map. (It only affects the game if clothing_noTP is set as false)
    clothing_masks[] = { "" };

    /* Escape Menu Configuration */
    escapeMenu_timer = 20; //Time required to pass before you can click the abort button in the escape menu.
    escapeMenu_displayExtras = true; //Display the players UID & serverName specified below in the escape menu.
    escapeMenu_displayText = "Thanks for playing!"; //Text displayed in the escape menu. Make it short.. around 20 characters.

    /* Fuel System Configurations */
    pump_service = true; //Allow users to use pump service on the map. Default = false
    fuel_cost = 200; //Cost of fuel per liter at fuel stations (if not defined for the vehicle already).
    service_chopper = 1000; //Cost to service chopper at chopper service station(Repair/Refuel).
    fuelCan_refuel = 250; //Cost to refuel an empty fuel canister at the fuel station pumps. (Be wary of your buy/sell prices on fuel cans to prevent exploits...)

    /* Gang System Configurations */
    gang_price = 150000; //Gang creation price. --Remember they are persistent so keep it reasonable to avoid millions of gangs.
    gang_upgradeBase = 13000; //The base cost for purchasing additional slots in a gang
    gang_upgradeMultiplier = 2.5; //CURRENTLY NOT IN USE

    /* Housing System Configurations */
    house_limit = 3; //Maximum number of houses a player can own.
    houseGarage_buyPrice = 1000000;
    houseGarage_sellPrice = 850000;

    /* Hunting & Fishing System Configurations */
    animaltypes_fish[] = { "Salema_F", "Ornate_random_F", "Mackerel_F", "Tuna_F", "Mullet_F", "CatShark_F", "Turtle_F" }; //Classnames of fish you can catch
    animaltypes_hunting[] = { "Sheep_random_F", "Goat_random_F", "Hen_random_F", "Cock_random_F", "Rabbit_F" }; //Classnames of aniamls you can hunt/gut

    /* Item-related Restrictions */
    restrict_medic_weapons = true; //Set to false to allow medics to use any weapon --true will remove ANY weapon they attempt to use (primary,secondary,launcher)
    restrict_clothingPickup = true; //Set to false to allow civilians to pickup/take any uniform (ground/crates/vehicles)
    restrict_weaponPickup = false; //Set to false to allow civilians to pickup/take any weapon (ground/crates/vehicles)
    restricted_uniforms[] = { "U_Rangemaster" };
    restricted_weapons[] = {  };

    /* Jail System Configurations */
    jail_seize_vItems[] = { "demolitioncharge", "barrel", "butt", "sight", "trigger", "engine", "plans", "beer", "whiskey", "moonshine", "zipties", "blindfold", "counterfitCash", "codeCracker", "spikeStrip","lockpick","goldenbarz3","blastingcharge","boltcutter","defusekit","heroin_unprocessed","heroin_processed","cannabis","marijuana","cocaine_unprocessed","cocaine_processed","turtle_raw" }; //Define VIRTUAL items you want to be removed from players upon jailing here. Use "jail_seize_inventory" for Arma inventory items.
    jail_seize_inventory = true; //Set to true to run the cop seize script on inmates. False will remove only weapons and magazines otherwise. (Basically used in case cops forget to seize items). [See Lines 106-111 below]
    sendtoJail_locations[] = { "jail_marker" }; //Enter the variableName from the mission.sqm here to allow cops to send a person to jail at these locations.
    jail_forceWalk = true;

    /* Medical System Configurations */
    revive_cops = true; //true to enable cops the ability to revive everyone or false for only medics/ems.
    revive_civ = false; //true to enable civs the ability to revive everyone or false for only medics/ems or medic/ems/cops.
    revive_east = false; //true to enable opfor the ability to revive everyone or false for only medics/ems or medic/ems/cops.
    revive_fee = 8500; //Revive fee that players have to pay and medics only EMS(independent) are rewarded with this amount.
    hospital_heal_fee = 50; //Fee to heal at a hospital NPC

    /* Paycheck & Bank System Configurations */
    bank_cop = 500000; //Amount of cash in bank for new cops
    bank_civ = 500000; //Amount of cash in bank for new civillians
    bank_med = 500000; //Amount of cash in bank for new medics

    paycheck_cop = 9500; //Payment for cops
    paycheck_civ = 7250; //Payment for civillians
    paycheck_med = 11250; //Payment for medics

    paycheck_period = 10; //Scaled in minutes
    bank_transferTax = .05; //Tax that player pays when transferring money from ATM. Tax = Amount * multiplier

    /* Player Job System Configurations */
    fuelTank_winMultiplier = 1; //Win Multiplier in FuelTank Missions. Increase for greater payout. Default = 1

    /* Search & Seizure System Configurations */
    seize_exempt[] = { "Binocular", "ItemWatch", "ItemCompass", "ItemGPS", "ItemMap", "Chemlight_red", "Chemlight_yellow", "Chemlight_green", "Chemlight_blue" }; //Arma items that will not get seized from player inventories
    seize_uniform[] = { "U_Rangemaster" }; //Any specific uniforms you want to be seized from players
    seize_vest[] = { "V_TacVest_blk_POLICE" }; //Any specific vests you want to be seized from players
    seize_headgear[] = { "H_Cap_police" }; //Any hats or helmets you want seized from players
    seize_minimum_rank = 1; //Required minimum CopLevel to be able to seize items from players

    /* Vehicle System Configurations */
    chopShop_vehicles[] = { "Car", "Air" }; //Vehicles that can be chopped. (Can add: "Ship" and possibly more -> look at the BI wiki...)
    vehicle_infiniteRepair[] = {true, true, true, true}; //Set to true for unlimited repairs with 1 toolkit. False will remove toolkit upon use. civilian, west, independent, east
    vehicle_infiniteRepairFalse[] = {false, false, false, false}; //Set to true for unlimited repairs with 1 toolkit. False will remove toolkit upon use. civilian, west, independent, east
    vehicleShop_rentalOnly[] = { "B_MRAP_01_hmg_F", "B_T_LSV_01_armed_F", "O_T_LSV_02_armed_F", "B_G_Offroad_01_armed_F", "B_Boat_Armed_01_minigun_F" }; //Vehicles that can only be rented and not purchased. (Last only for the session)
    vehicleShop_3D = true; //Add preview 3D inside Shop vehicle.       Default : False

    /* Vehicle Purchase Prices */
    vehicle_purchase_multiplier_CIVILIAN = 1; //Civilian Vehicle Buy Price = Config_Vehicle price * multiplier
    vehicle_purchase_multiplier_COP = .75; //Cop Vehicle Buy Price = Config_Vehicle price * multiplier
    vehicle_purchase_multiplier_MEDIC = .01; //Medic Vehicle Buy Price = Config_Vehicle price * multiplier
    vehicle_purchase_multiplier_OPFOR = -1; // -- NOT IN USE -- Simply left in for east support.

    /* Vehicle Rental Prices */
    vehicle_rental_multiplier_CIVILIAN = .80; //Civilian Vehicle Rental Price = Config_Vehicle price * multiplier
    vehicle_rental_multiplier_COP = .3; //Cop Vehicle Rental Price = Config_Vehicle price * multiplier
    vehicle_rental_multiplier_MEDIC = .55; //Medic Vehicle Rental Price = Config_Vehicle price * multiplier
    vehicle_rental_multiplier_OPFOR = -1; // -- NOT IN USE -- Simply left in for east support.

    /* Vehicle Sell Prices */
    vehicle_sell_multiplier_CIVILIAN = .5; //Civilian Vehicle Garage Sell Price = Vehicle Buy Price * multiplier
    vehicle_sell_multiplier_COP = .5; //Cop Vehicle Garage Sell Price = Vehicle Buy Price * multiplier
    vehicle_sell_multiplier_MEDIC = .5; //Medic Vehicle Garage Sell Price = Vehicle Buy Price * multiplier
    vehicle_sell_multiplier_OPFOR = -1; // -- NOT IN USE -- Simply left in for east support.

    /* Vehicle Insurance Prices */ 
    vehicle_insurance_multiplier_CIVILIAN = .35; //Civilian Vehicle Insurance Price = Vehicle Buy Price * multiplier 
    vehicle_insurance_multiplier_COP = .15; //Cop Vehicle Insurance Price = Vehicle Buy Price * multiplier 
    vehicle_insurance_multiplier_MEDIC = .1; //Medic Vehicle Insurance Price = Vehicle Buy Price * multiplier 
    vehicle_insurance_multiplier_OPFOR = -1; // -- NOT IN USE -- Simply left in for east support.

    /* "Other" Vehicle Prices */
    vehicle_chopShop_multiplier = .25; //Chop Shop price for vehicles. TO AVOID EXPLOITS NEVER SET HIGHER THAN A PURCHASE/RENTAL multipler!   Payout = Config_vehicle Price * multiplier
    vehicle_storage_fee_multiplier = .05; //Pull from garage cost --> Cost takes the playersides Buy Price * multiplier
    vehicle_cop_impound_multiplier = .2; //TO AVOID EXPLOITS NEVER SET HIGHER THAN A PURCHASE/RENTAL multipler!   Payout = Config_vehicle Price * multiplier

    disableCommanderView = true; //false - Group leaders can access the commander view. true [default] - Group leaders cannot access the commander view.
                                 //Commander/tactical view is accessed via pressing . [NUM] by default. It raises the camera significantly higher and steeper above the player in order to give a boarder tactical view of the surrounding area.

    	/* Bounty System Settings *
    /* bountys[] = {string, amount, code} */
    bountys[] = {
		{"STR_Bounty_5000", "500", "1B"},
		{"STR_Bounty_10000", "1000", "2B"},
		{"STR_Bounty_15000", "1500", "3B"},
		{"STR_Bounty_20000", "2000", "4B"},
		{"STR_Bounty_25000", "2500", "5B"},
		{"STR_Bounty_30000", "3000", "6B"},
		{"STR_Bounty_35000", "3500", "7B"},
		{"STR_Bounty_40000", "4000", "8B"},
		{"STR_Bounty_45000", "4500", "9B"},
		{"STR_Bounty_50000", "5000", "10B"},
		{"STR_Bounty_55000", "5500", "11B"},
		{"STR_Bounty_60000", "6000", "12B"},
		{"STR_Bounty_65000", "6500", "13B"},
		{"STR_Bounty_70000", "7000", "14B"},
		{"STR_Bounty_75000", "7500", "15B"},
		{"STR_Bounty_80000", "8000", "16B"},
		{"STR_Bounty_85000", "8500", "17B"},
		{"STR_Bounty_90000", "9000", "18B"},
		{"STR_Bounty_95000", "9500", "19B"},
		{"STR_Bounty_100000", "10000", "20B"},
		{"STR_Bounty_200000", "20000", "21B"},
		{"STR_Bounty_300000", "30000", "22B"},
		{"STR_Bounty_400000", "40000", "23B"},
		{"STR_Bounty_500000", "50000", "24B"},
		{"STR_Bounty_1000000", "100000", "25B"}
	};                             

    /* Wanted System Settings *
    /* crimes[] = {String, Bounty, Code} */
    crimes[] = {
		{"STR_Crime_11","1500","11"}, // Failure to Maintain Altitude
		{"STR_Crime_12","1500","12"}, // Illegal Landing
		{"STR_Crime_13","1500","13"}, // Failure to use Collision Lights
		{"STR_Crime_14","1000","14"}, // Flying without a Pilot's License
		{"STR_Crime_100","1000","100"}, // Disorderly Conduct
		{"STR_Crime_101","1250","101"}, // Indecent Exposure
		{"STR_Crime_102","1500","102"}, // Insuranc Fraud
		{"STR_Crime_103","1100","103"}, // Concealing Identity
		{"STR_Crime_104","1000","104"}, // Disturbing the Peace
		{"STR_Crime_105","1500","105"}, // Possession of Illegal Items
		{"STR_Crime_106","1250","106"}, // Failure to Comply with Officer
		{"STR_Crime_107","1250","107"}, // Obstruction of Justice
		{"STR_Crime_108","1250","108"}, // Possession of Police Equipment
		{"STR_Crime_109","1500","109"}, // Impersonatig a Police Officer
		{"STR_Crime_110","1000","110"}, // Trespassing on Private Property
		{"STR_Crime_110P","1200","110P"}, // Trespassing on Police Property
		{"STR_Crime_111","1500","111"}, // Threatening a Civilian
		{"STR_Crime_111P","1500","111P"}, // Threatening an Officer
		{"STR_Crime_187","5500","187"}, // Manslaughter
		{"STR_Crime_187P","7500","187P"}, // Manslaughter of a LEO
		{"STR_Crime_188","2750","188"}, // Attp. Manslaughter
		{"STR_Crime_188P","3750","188P"}, // Attp. Manslaughter of a LEO
		{"STR_Crime_189","2000","189"}, // Evading Arrest on Foot
		{"STR_Crime_189V","2000","189V"}, // Evading Arrest in a Vehicle
		{"STR_Crime_190","1500","190"}, // Breaking and Entering unowned Property 
		{"STR_Crime_215","1000","215"}, // Attp. Grand Theft Auto
		{"STR_Crime_216","1500","216"}, // Grand Theft Auto 487
		{"STR_Crime_217","1000","217"}, // Attp. Burglary
		{"STR_Crime_218","1500","218"}, // Burglary
		{"STR_Crime_219","1000","219"}, // Attp. Theft
		{"STR_Crime_220","1500","220"}, // Theft
		{"STR_Crime_221","1000","221"}, // Attp. Robbery
		{"STR_Crime_222","1500","222"}, // Robbery 211
		{"STR_Crime_481","2450","481"}, // Misdemeanor Drug Possession
		{"STR_Crime_482","3500","482"}, // Felony Drug Possession
		{"STR_Crime_483","3500","483"}, // Drug Trafficking
		{"STR_Crime_484","3500","484"}, // Drug Dealing
		{"STR_Crime_485","3500","485"}, // Intent To Distribute 482
		{"STR_Crime_390","500","390"}, // Public Intoxication
		{"STR_Crime_390D","1500","390D"}, // Driving Under The Influence
		{"STR_Crime_400","1800","400"}, // Attp. Kidnapping
		{"STR_Crime_400P","2700","400P"}, // Attp. Kidnapping of a LEO
		{"STR_Crime_401","2000","401"}, // Kidnapping 207
		{"STR_Crime_401P","3000","401P"}, // Kidnapping of a LEO
		{"STR_Crime_23","10000","23"}, // Federal Reserve Robbery
		{"STR_Crime_25","1500","25"}, // Destruction of Public Property
		{"STR_Crime_901","7500","901"}, // Escaping from Jail
		{"STR_Crime_901A","5000","901A"}, // Aiding in a Jailbreak
		{"STR_Crime_666","10000","666"}, // Terrorism 667
		{"STR_Crime_700","2000","700"}, // Possession of Hostages
		{"STR_Crime_701","1500","701"}, // Assault
		{"STR_Crime_701P","1800","701P"}, // Assualt of a LEO
		{"STR_Crime_4","2500","4"}, // Speeding Inside City Limits 4
		{"STR_Crime_4O","3500","4O"}, // Speeding Outside City Limits
		{"STR_Crime_2","750","2"}, // Reckless Driving
		{"STR_Crime_1","1000","1"}, // Driving Without a License
		{"STR_Crime_5","2000","5"}, // Failure to use Headlights
		{"STR_Crime_3","1000","3"}, // Failure to Stop for Police/EMS
		{"STR_Crime_8","2000","8"}, // Driving an Illegal Vehicle
		{"STR_Crime_186","2750","186"}, // Attp. Vehicular Manslaughter
		{"STR_Crime_186P","3750","186P"}, // Attp. Vehicular Manslaughter of a LEO
		{"STR_Crime_187V","1500","187V"}, // Vehicluar Manslaughter
		{"STR_Crime_187VP","1500","187VP"}, // Vehicluar Manslaughter of a LEO
		{"STR_Crime_480","750","480"}, // Hit and Run Property 480
		{"STR_Crime_481","500","481"}, // Hit and Run Personal Injury
		{"STR_Crime_15","1000","15"}, // Obstruction of Traffic
		{"STR_Crime_16","1000","16"}, // Obstruction of an Entryway
		{"STR_Crime_17","500","17"}, // Driving without a Helmet
		{"STR_Crime_18","1000","18"}, // Possession of a Firearm without a License 14
		{"STR_Crime_19","2500","19"}, // Possession of an Illegal Firearm 15
		{"STR_Crime_20","500","20"}, // Discharging a Firearm inside City Limits
		{"STR_Crime_21","750","21"} // Brandishing a Firearm in Public
    };
};


#include "Config_Clothing.hpp"
#include "Config_Licenses.hpp"
#include "Config_Vehicles.hpp"
#include "Config_vItems.hpp"
#include "Config_Weapons.hpp"
#include "Config_Gather.hpp"
#include "Config_SpawnPoints.hpp"
#include "Config_Process.hpp"
#include "Config_Housing.hpp"
#include "Config_Garages.hpp"
#include "Config_Banking.hpp"
#include "Config_GPSPoints.hpp"
#include "Config_eXpandedHousing.hpp"
#include "Config_Lumbering.hpp"

