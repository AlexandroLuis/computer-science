-- phpMyAdmin SQL Dump
-- version 2.6.0-pl3
-- http://www.phpmyadmin.net
-- 
-- V�rd: 195.245.210.174
-- Skapad: 04 februari 2005 kl 21:09
-- Serverversion: 4.0.15
-- PHP-version: 4.3.10
-- 
-- webmessenger client db
-- 
-- 
-- Databas: `free57654`
-- 
CREATE DATABASE `free57654`;
USE free57654;

-- --------------------------------------------------------

-- 
-- Struktur f�r tabell `ChatDetail`
-- 
-- Skapades: 18 december 2004 kl 16:58
-- Senaste uppdatering: 19 januari 2005 kl 02:03
-- 

CREATE TABLE `ChatDetail` (
  `ChatID` int(6) NOT NULL auto_increment,
  `ConversationStartDateTime` datetime NOT NULL default '0000-00-00 00:00:00',
  `ConversationEndDateTime` datetime NOT NULL default '0000-00-00 00:00:00',
  `RecordedBy` int(3) NOT NULL default '0',
  `Conversation` text NOT NULL,
  PRIMARY KEY  (`ChatID`)
) TYPE=MyISAM COMMENT='Saves chat details and conversation' AUTO_INCREMENT=5 ;

-- 
-- Data i tabell `ChatDetail`
-- 

INSERT INTO `ChatDetail` (`ChatID`, `ConversationStartDateTime`, `ConversationEndDateTime`, `RecordedBy`, `Conversation`) VALUES (1, '2004-12-25 23:22:22', '2004-12-26 00:15:15', 6, 'Marko:This is a test!\n Marko:Testing the database!\n');
INSERT INTO `ChatDetail` (`ChatID`, `ConversationStartDateTime`, `ConversationEndDateTime`, `RecordedBy`, `Conversation`) VALUES (2, '2004-12-27 21:25:20', '2004-12-28 00:13:15', 6, ' jonas [ home ] says: ok good..\n zahid says: i can not 2\n...iffi... says: yah its good now ');
INSERT INTO `ChatDetail` (`ChatID`, `ConversationStartDateTime`, `ConversationEndDateTime`, `RecordedBy`, `Conversation`) VALUES (3, '2004-12-27 21:25:20', '2004-12-28 00:13:15', 6, ' jonas [ home ] says: have u tried to put in info in database?\n jonas [ home ] says: Irfan: how should the data looks like for the conversations in database??\n Zdenek says: on my pc it works i have something done in my local db');
INSERT INTO `ChatDetail` (`ChatID`, `ConversationStartDateTime`, `ConversationEndDateTime`, `RecordedBy`, `Conversation`) VALUES (4, '2004-12-27 21:25:20', '2004-12-28 00:13:15', 6, ' zahid says:\n\r\nok Marko, Zedenik whats about u, can you make change to night\n\r\nZdenek says: \n yes\n jonas [ home ] says: \n Zahid: what do i need to do about 5.2 Page 7?? \n zahid says: \n what is the heading\n Marko says: \n we( I ) have to change 6.1 and 6.2? \n jonas [ home ] says: \n 5.2	Work Products and Deliverables\n zahid says: \n jonas can u tell me the heading\n zahid says: \n yes \n zahid says: \n wait\n jonas [ home ] says: \n I couldnt find any 7.2 so asume that u meant 7.1... \n jonas [ home ] says: \n what i needed to look at... \n zahid says: \n you have check that if any of the deliverable late, or i have written correct\n zahid says: \n if late then if you want to add remark you can\n jonas [ home ] says: \n ok.. i do that... \n zahid says: \n otherwise nothing\n jonas [ home ] says: \n Zahid: I couldnt find any 7.2 so asume that u meant 7.1... \n zahid says: \n jyes yes\n zahid says: \n sorry this is my mistake\n ');

-- --------------------------------------------------------

-- 
-- Struktur f�r tabell `ChatSession`
-- 
-- Skapades: 18 december 2004 kl 16:58
-- Senaste uppdatering: 21 januari 2005 kl 00:46
-- 

CREATE TABLE `ChatSession` (
  `TBlID` int(6) NOT NULL auto_increment,
  `ChatID` int(6) NOT NULL default '0',
  `MemberID` int(3) NOT NULL default '0',
  `ProjectID` int(3) NOT NULL default '0',
  `MessengerID` int(2) NOT NULL default '0',
  PRIMARY KEY  (`TBlID`)
) TYPE=MyISAM COMMENT='Keeps chat sessions' AUTO_INCREMENT=25 ;

-- 
-- Data i tabell `ChatSession`
-- 

INSERT INTO `ChatSession` (`TBlID`, `ChatID`, `MemberID`, `ProjectID`, `MessengerID`) VALUES (1, 1, 1, 1, 1);
INSERT INTO `ChatSession` (`TBlID`, `ChatID`, `MemberID`, `ProjectID`, `MessengerID`) VALUES (2, 2, 5, 1, 0);
INSERT INTO `ChatSession` (`TBlID`, `ChatID`, `MemberID`, `ProjectID`, `MessengerID`) VALUES (3, 3, 5, 1, 0);
INSERT INTO `ChatSession` (`TBlID`, `ChatID`, `MemberID`, `ProjectID`, `MessengerID`) VALUES (4, 4, 5, 1, 0);

-- --------------------------------------------------------

-- 
-- Struktur f�r tabell `FeedBack`
-- 
-- Skapades: 18 december 2004 kl 16:58
-- Senaste uppdatering: 18 december 2004 kl 16:58
-- 

CREATE TABLE `FeedBack` (
  `SenderID` int(4) NOT NULL auto_increment,
  `FirstName` varchar(20) NOT NULL default '',
  `LastName` varchar(20) NOT NULL default '',
  `Email` varchar(30) NOT NULL default '',
  `CurrentDate` date NOT NULL default '0000-00-00',
  `Comments` varchar(255) NOT NULL default '',
  PRIMARY KEY  (`SenderID`)
) TYPE=MyISAM COMMENT='saves feedback from users' AUTO_INCREMENT=1 ;

-- 
-- Data i tabell `FeedBack`
-- 


-- --------------------------------------------------------

-- 
-- Struktur f�r tabell `Guest`
-- 
-- Skapades: 18 december 2004 kl 16:58
-- Senaste uppdatering: 18 december 2004 kl 16:58
-- 

CREATE TABLE `Guest` (
  `GuestID` int(3) NOT NULL auto_increment,
  `GuestUseMessengerID` int(2) NOT NULL default '0',
  `GuestMessengerAddress` varchar(30) NOT NULL default '',
  `ChatID` int(6) NOT NULL default '0',
  PRIMARY KEY  (`GuestID`)
) TYPE=MyISAM COMMENT='Keeps guests information participating in chatting' AUTO_INCREMENT=1 ;

-- 
-- Data i tabell `Guest`
-- 


-- --------------------------------------------------------

-- 
-- Struktur f�r tabell `MemberInProject`
-- 
-- Skapades: 18 december 2004 kl 16:58
-- Senaste uppdatering: 20 januari 2005 kl 14:12
-- 

CREATE TABLE `MemberInProject` (
  `ProjectID` int(3) NOT NULL default '0',
  `MemberID` int(3) NOT NULL default '0'
) TYPE=MyISAM COMMENT='Keeps team members record in which project they are working';

-- 
-- Data i tabell `MemberInProject`
-- 

INSERT INTO `MemberInProject` (`ProjectID`, `MemberID`) VALUES (2, 6);
INSERT INTO `MemberInProject` (`ProjectID`, `MemberID`) VALUES (2, 7);
INSERT INTO `MemberInProject` (`ProjectID`, `MemberID`) VALUES (3, 5);
INSERT INTO `MemberInProject` (`ProjectID`, `MemberID`) VALUES (1, 1);
INSERT INTO `MemberInProject` (`ProjectID`, `MemberID`) VALUES (3, 1);
INSERT INTO `MemberInProject` (`ProjectID`, `MemberID`) VALUES (1, 5);
INSERT INTO `MemberInProject` (`ProjectID`, `MemberID`) VALUES (1, 4);
INSERT INTO `MemberInProject` (`ProjectID`, `MemberID`) VALUES (2, 5);

-- --------------------------------------------------------

-- 
-- Struktur f�r tabell `MembersMsngrAccount`
-- 
-- Skapades: 18 december 2004 kl 16:58
-- Senaste uppdatering: 18 december 2004 kl 16:58
-- 

CREATE TABLE `MembersMsngrAccount` (
  `MemberID` int(3) NOT NULL default '0',
  `MessengerID` int(2) NOT NULL default '0',
  `MesengerAccountID` varchar(30) NOT NULL default ''
) TYPE=MyISAM COMMENT='Keeps record of messengers Ids(which member has which messen';

-- 
-- Data i tabell `MembersMsngrAccount`
-- 

INSERT INTO `MembersMsngrAccount` (`MemberID`, `MessengerID`, `MesengerAccountID`) VALUES (1, 1, 'jonaswadsten@hotmail.com');
INSERT INTO `MembersMsngrAccount` (`MemberID`, `MessengerID`, `MesengerAccountID`) VALUES (1, 2, '33830163');
INSERT INTO `MembersMsngrAccount` (`MemberID`, `MessengerID`, `MesengerAccountID`) VALUES (2, 1, 'nice_pak@hotmail.com');
INSERT INTO `MembersMsngrAccount` (`MemberID`, `MessengerID`, `MesengerAccountID`) VALUES (3, 2, '208493173');
INSERT INTO `MembersMsngrAccount` (`MemberID`, `MessengerID`, `MesengerAccountID`) VALUES (3, 1, 'e-fik123@seznam.cz');
INSERT INTO `MembersMsngrAccount` (`MemberID`, `MessengerID`, `MesengerAccountID`) VALUES (4, 1, 'zahidmukhtar77@hotmail.com');
INSERT INTO `MembersMsngrAccount` (`MemberID`, `MessengerID`, `MesengerAccountID`) VALUES (5, 1, 'MarkoB59@hotmail.com');
INSERT INTO `MembersMsngrAccount` (`MemberID`, `MessengerID`, `MesengerAccountID`) VALUES (6, 1, 'tihana2004@hotmail.com');

-- --------------------------------------------------------

-- 
-- Struktur f�r tabell `Messenger`
-- 
-- Skapades: 18 december 2004 kl 16:58
-- Senaste uppdatering: 18 december 2004 kl 16:58
-- 

CREATE TABLE `Messenger` (
  `MessengerID` int(2) NOT NULL auto_increment,
  `MessengerName` varchar(20) NOT NULL default '',
  `PortNumber` int(4) NOT NULL default '0',
  PRIMARY KEY  (`MessengerID`)
) TYPE=MyISAM COMMENT='Keeps chat messengers information' AUTO_INCREMENT=3 ;

-- 
-- Data i tabell `Messenger`
-- 

INSERT INTO `Messenger` (`MessengerID`, `MessengerName`, `PortNumber`) VALUES (1, 'MSN Messengerl', 1863);
INSERT INTO `Messenger` (`MessengerID`, `MessengerName`, `PortNumber`) VALUES (2, 'ICQ', 5190);

-- --------------------------------------------------------

-- 
-- Struktur f�r tabell `Project`
-- 
-- Skapades: 18 januari 2005 kl 13:08
-- Senaste uppdatering: 20 januari 2005 kl 00:36
-- 

CREATE TABLE `Project` (
  `ProjectID` int(3) NOT NULL auto_increment,
  `ProjectName` varchar(30) NOT NULL default '',
  `StartDate` date NOT NULL default '0000-00-00',
  `EndDate` date NOT NULL default '0000-00-00',
  `AddedBy` int(2) NOT NULL default '0',
  `Deleted` int(1) NOT NULL default '0',
  PRIMARY KEY  (`ProjectID`)
) TYPE=MyISAM COMMENT='Keeps project information' AUTO_INCREMENT=8 ;

-- 
-- Data i tabell `Project`
-- 

INSERT INTO `Project` (`ProjectID`, `ProjectName`, `StartDate`, `EndDate`, `AddedBy`, `Deleted`) VALUES (1, 'Messenger Client', '2004-11-02', '2005-11-01', 1, 0);
INSERT INTO `Project` (`ProjectID`, `ProjectName`, `StartDate`, `EndDate`, `AddedBy`, `Deleted`) VALUES (2, 'Project 05', '2005-01-21', '2005-05-05', 3, 0);
INSERT INTO `Project` (`ProjectID`, `ProjectName`, `StartDate`, `EndDate`, `AddedBy`, `Deleted`) VALUES (3, 'test2', '2005-01-03', '2005-02-25', 1, 1);
INSERT INTO `Project` (`ProjectID`, `ProjectName`, `StartDate`, `EndDate`, `AddedBy`, `Deleted`) VALUES (7, 'jonas testing 3', '2005-05-26', '2006-04-22', 1, 0);

-- --------------------------------------------------------

-- 
-- Struktur f�r tabell `TeamMember`
-- 
-- Skapades: 14 januari 2005 kl 11:18
-- Senaste uppdatering: 20 januari 2005 kl 14:11
-- 

CREATE TABLE `TeamMember` (
  `MemberID` int(3) NOT NULL auto_increment,
  `UserName` varchar(20) NOT NULL default '',
  `Password` varchar(20) NOT NULL default '',
  `FirstName` varchar(20) NOT NULL default '',
  `LastName` varchar(20) NOT NULL default '',
  `Email` varchar(25) NOT NULL default '',
  `EntryDate` date NOT NULL default '0000-00-00',
  `Phone` int(14) NOT NULL default '0',
  `AccessRights` varchar(20) NOT NULL default '',
  `Designation` varchar(20) NOT NULL default '',
  `Visitor` varchar(10) default NULL,
  `Company` varchar(20) NOT NULL default '',
  `Deleted` int(1) NOT NULL default '0',
  PRIMARY KEY  (`MemberID`)
) TYPE=MyISAM AUTO_INCREMENT=11 ;

-- 
-- Data i tabell `TeamMember`
-- 

INSERT INTO `TeamMember` (`MemberID`, `UserName`, `Password`, `FirstName`, `LastName`, `Email`, `EntryDate`, `Phone`, `AccessRights`, `Designation`, `Visitor`, `Company`, `Deleted`) VALUES (1, 'jonaswadsten', 'jw72', 'jonas', 'wadsten', 'jonas@wadsten.nu', '2004-12-13', 2147483647, '3', '', '', 'mdh/hig', 0);
INSERT INTO `TeamMember` (`MemberID`, `UserName`, `Password`, `FirstName`, `LastName`, `Email`, `EntryDate`, `Phone`, `AccessRights`, `Designation`, `Visitor`, `Company`, `Deleted`) VALUES (2, 'irfantahir', 'it04', 'Irfan', 'Tahir', '', '2004-12-13', 0, '2', '', NULL, '', 0);
INSERT INTO `TeamMember` (`MemberID`, `UserName`, `Password`, `FirstName`, `LastName`, `Email`, `EntryDate`, `Phone`, `AccessRights`, `Designation`, `Visitor`, `Company`, `Deleted`) VALUES (3, 'zdeneksvoboda', 'aa', 'Zdenek', 'Svoboda', 'E-fik123@seznam.cz', '2004-12-13', 576788096, '3', '', NULL, 'VanDread', 0);
INSERT INTO `TeamMember` (`MemberID`, `UserName`, `Password`, `FirstName`, `LastName`, `Email`, `EntryDate`, `Phone`, `AccessRights`, `Designation`, `Visitor`, `Company`, `Deleted`) VALUES (4, 'zahidmukhtar', 'zm04', 'Zahid', 'Mukhtar', '', '2004-12-13', 0, '1', '', NULL, '', 0);
INSERT INTO `TeamMember` (`MemberID`, `UserName`, `Password`, `FirstName`, `LastName`, `Email`, `EntryDate`, `Phone`, `AccessRights`, `Designation`, `Visitor`, `Company`, `Deleted`) VALUES (5, 'markobejuk', 'mb05', 'Marko', 'Bejuk', '', '2004-12-13', 0, '3', '', NULL, '', 0);
INSERT INTO `TeamMember` (`MemberID`, `UserName`, `Password`, `FirstName`, `LastName`, `Email`, `EntryDate`, `Phone`, `AccessRights`, `Designation`, `Visitor`, `Company`, `Deleted`) VALUES (6, 'tihanaknaffl', 'tk04', 'Tihana', 'Knaffl', '', '2004-12-13', 0, '3', '', NULL, '', 0);
INSERT INTO `TeamMember` (`MemberID`, `UserName`, `Password`, `FirstName`, `LastName`, `Email`, `EntryDate`, `Phone`, `AccessRights`, `Designation`, `Visitor`, `Company`, `Deleted`) VALUES (7, 'pepa', 'pp', 'pepa', 'last', 'last@email.com', '2005-01-14', 123456, '2', '', NULL, 'dad', 0);
INSERT INTO `TeamMember` (`MemberID`, `UserName`, `Password`, `FirstName`, `LastName`, `Email`, `EntryDate`, `Phone`, `AccessRights`, `Designation`, `Visitor`, `Company`, `Deleted`) VALUES (8, 'jonastestar', 'jw72', 'jonas', 'testar', 'test@twst.se', '0000-00-00', 2147483647, '3', '', NULL, 'tes', 0);
INSERT INTO `TeamMember` (`MemberID`, `UserName`, `Password`, `FirstName`, `LastName`, `Email`, `EntryDate`, `Phone`, `AccessRights`, `Designation`, `Visitor`, `Company`, `Deleted`) VALUES (9, 'test member', 'jw72', 'jonas', 'testing', 'test@test.clm', '0000-00-00', 34154154, '3', '', NULL, 'test', 0);
INSERT INTO `TeamMember` (`MemberID`, `UserName`, `Password`, `FirstName`, `LastName`, `Email`, `EntryDate`, `Phone`, `AccessRights`, `Designation`, `Visitor`, `Company`, `Deleted`) VALUES (10, 'tesmember04', 'test', '', '', '', '0000-00-00', 0, '2', '', NULL, '', 0);
