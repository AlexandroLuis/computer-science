CREATE TABLE `exercicio` (
	`id` int(11) NOT NULL,
	`name` varchar(255) NOT NULL,
	`description` varchar(255) NOT NULL,
	`class` varchar(50) NOT NULL,
	`level` INT(2) NOT NULL,
	`source` longtext(1000) NOT NULL,
	PRIMARY KEY (`id`)
);

