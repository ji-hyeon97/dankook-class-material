-- MySQL dump 10.13  Distrib 8.0.23, for Win64 (x86_64)
--
-- Host: localhost    Database: sampledb
-- ------------------------------------------------------
-- Server version	8.0.23

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `ptable`
--

DROP TABLE IF EXISTS `ptable`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `ptable` (
  `number` int NOT NULL,
  `name` text NOT NULL,
  `symbol` text NOT NULL,
  `weight` double NOT NULL,
  `numberOfNeutrons` int NOT NULL,
  `numberOfProtons` int NOT NULL,
  `numberOfElectrons` int NOT NULL,
  `period` int NOT NULL,
  `group` int DEFAULT NULL,
  `phase` text NOT NULL,
  PRIMARY KEY (`number`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ptable`
--

LOCK TABLES `ptable` WRITE;
/*!40000 ALTER TABLE `ptable` DISABLE KEYS */;
INSERT INTO `ptable` VALUES (1,'Hydrogen','H',1.007,0,1,1,1,1,'GAS'),(2,'Helium','He',4.002,2,2,2,1,18,'GAS'),(3,'Lithium','Li',6.941,4,3,3,2,1,'SOLID'),(4,'Beryllium','Be',9.012,5,4,4,2,2,'SOLID'),(5,'Boron','B',10.811,6,5,5,2,13,'SOLID'),(6,'Carbon','C',12.011,6,6,6,2,14,'SOLID'),(7,'Nitrogen','N',14.007,7,7,7,2,15,'GAS'),(8,'Oxygen','O',15.999,8,8,8,2,16,'GAS'),(9,'Fluorine','F',18.998,10,9,9,2,17,'GAS'),(10,'Neon','Ne',20.18,10,10,10,2,18,'GAS'),(11,'Sodium','Na',22.99,12,11,11,3,1,'SOLID'),(12,'Magnesium','Mg',24.305,12,12,12,3,2,'SOLID'),(13,'Aluminum','Al',26.982,14,13,13,3,13,'SOLID'),(14,'Silicon','Si',28.086,14,14,14,3,14,'SOLID'),(15,'Phosphorus','P',30.974,16,15,15,3,15,'SOLID'),(16,'Sulfur','S',32.065,16,16,16,3,16,'SOLID'),(17,'Chlorine','Cl',35.453,18,17,17,3,17,'GAS'),(18,'Argon','Ar',39.948,22,18,18,3,18,'GAS'),(19,'Potassium','K',39.098,20,19,19,4,1,'SOLID'),(20,'Calcium','Ca',40.078,20,20,20,4,2,'SOLID'),(21,'Scandium','Sc',44.956,24,21,21,4,3,'SOLID'),(22,'Titanium','Ti',47.867,26,22,22,4,4,'SOLID'),(23,'Vanadium','V',50.942,28,23,23,4,5,'SOLID'),(24,'Chromium','Cr',51.996,28,24,24,4,6,'SOLID'),(25,'Manganese','Mn',54.938,30,25,25,4,7,'SOLID'),(26,'Iron','Fe',55.845,30,26,26,4,8,'SOLID'),(27,'Cobalt','Co',58.933,32,27,27,4,9,'SOLID'),(28,'Nickel','Ni',58.693,31,28,28,4,10,'SOLID'),(29,'Copper','Cu',63.546,35,29,29,4,11,'SOLID'),(30,'Zinc','Zn',65.38,35,30,30,4,12,'SOLID'),(31,'Gallium','Ga',69.723,39,31,31,4,13,'SOLID'),(32,'Germanium','Ge',72.64,41,32,32,4,14,'SOLID'),(33,'Arsenic','As',74.922,42,33,33,4,15,'SOLID'),(34,'Selenium','Se',78.96,45,34,34,4,16,'SOLID'),(35,'Bromine','Br',79.904,45,35,35,4,17,'LIQUID'),(36,'Krypton','Kr',83.798,48,36,36,4,18,'GAS'),(37,'Rubidium','Rb',85.468,48,37,37,5,1,'SOLID'),(38,'Strontium','Sr',87.62,50,38,38,5,2,'SOLID'),(39,'Yttrium','Y',88.906,50,39,39,5,3,'SOLID'),(40,'Zirconium','Zr',91.224,51,40,40,5,4,'SOLID'),(41,'Niobium','Nb',92.906,52,41,41,5,5,'SOLID'),(42,'Molybdenum','Mo',95.96,54,42,42,5,6,'SOLID'),(43,'Technetium','Tc',98,55,43,43,5,7,'UNKNOWN'),(44,'Ruthenium','Ru',101.07,57,44,44,5,8,'SOLID'),(45,'Rhodium','Rh',102.906,58,45,45,5,9,'SOLID'),(46,'Palladium','Pd',106.42,60,46,46,5,10,'SOLID'),(47,'Silver','Ag',107.868,61,47,47,5,11,'SOLID'),(48,'Cadmium','Cd',112.411,64,48,48,5,12,'SOLID'),(49,'Indium','In',114.818,66,49,49,5,13,'SOLID'),(50,'Tin','Sn',118.71,69,50,50,5,14,'SOLID'),(51,'Antimony','Sb',121.76,71,51,51,5,15,'SOLID'),(52,'Tellurium','Te',127.6,76,52,52,5,16,'SOLID'),(53,'Iodine','I',126.904,74,53,53,5,17,'SOLID'),(54,'Xenon','Xe',131.293,77,54,54,5,18,'GAS'),(55,'Cesium','Cs',132.905,78,55,55,6,1,'SOLID'),(56,'Barium','Ba',137.327,81,56,56,6,2,'SOLID'),(57,'Lanthanum','La',138.905,82,57,57,6,3,'SOLID'),(58,'Cerium','Ce',140.116,82,58,58,6,NULL,'SOLID'),(59,'Praseodymium','Pr',140.908,82,59,59,6,NULL,'SOLID'),(60,'Neodymium','Nd',144.242,84,60,60,6,NULL,'SOLID'),(61,'Promethium','Pm',145,84,61,61,6,NULL,'UNKNOWN'),(62,'Samarium','Sm',150.36,88,62,62,6,NULL,'SOLID'),(63,'Europium','Eu',151.964,89,63,63,6,NULL,'SOLID'),(64,'Gadolinium','Gd',157.25,93,64,64,6,NULL,'SOLID'),(65,'Terbium','Tb',158.925,94,65,65,6,NULL,'SOLID'),(66,'Dysprosium','Dy',162.5,97,66,66,6,NULL,'SOLID'),(67,'Holmium','Ho',164.93,98,67,67,6,NULL,'SOLID'),(68,'Erbium','Er',167.259,99,68,68,6,NULL,'SOLID'),(69,'Thulium','Tm',168.934,100,69,69,6,NULL,'SOLID'),(70,'Ytterbium','Yb',173.054,103,70,70,6,NULL,'SOLID'),(71,'Lutetium','Lu',174.967,104,71,71,6,NULL,'SOLID'),(72,'Hafnium','Hf',178.49,106,72,72,6,4,'SOLID'),(73,'Tantalum','Ta',180.948,108,73,73,6,5,'SOLID'),(74,'Wolfram','W',183.84,110,74,74,6,6,'SOLID'),(75,'Rhenium','Re',186.207,111,75,75,6,7,'SOLID'),(76,'Osmium','Os',190.23,114,76,76,6,8,'SOLID'),(77,'Iridium','Ir',192.217,115,77,77,6,9,'SOLID'),(78,'Platinum','Pt',195.084,117,78,78,6,10,'SOLID'),(79,'Gold','Au',196.967,118,79,79,6,11,'SOLID'),(80,'Mercury','Hg',200.59,121,80,80,6,12,'LIQUID'),(81,'Thallium','Tl',204.383,123,81,81,6,13,'SOLID'),(82,'Lead','Pb',207.2,125,82,82,6,14,'SOLID'),(83,'Bismuth','Bi',208.98,126,83,83,6,15,'SOLID'),(84,'Polonium','Po',210,126,84,84,6,16,'SOLID'),(85,'Astatine','At',210,125,85,85,6,17,'SOLID'),(86,'Radon','Rn',222,136,86,86,6,18,'GAS'),(87,'Francium','Fr',223,136,87,87,7,1,'SOLID'),(88,'Radium','Ra',226,138,88,88,7,2,'SOLID'),(89,'Actinium','Ac',227,138,89,89,7,3,'SOLID'),(90,'Thorium','Th',232.038,142,90,90,7,NULL,'SOLID'),(91,'Protactinium','Pa',231.036,140,91,91,7,NULL,'SOLID'),(92,'Uranium','U',238.029,146,92,92,7,NULL,'SOLID'),(93,'Neptunium','Np',237,144,93,93,7,NULL,'UNKNOWN'),(94,'Plutonium','Pu',244,150,94,94,7,NULL,'UNKNOWN'),(95,'Americium','Am',243,148,95,95,7,NULL,'UNKNOWN'),(96,'Curium','Cm',247,151,96,96,7,NULL,'UNKNOWN'),(97,'Berkelium','Bk',247,150,97,97,7,NULL,'UNKNOWN'),(98,'Californium','Cf',251,153,98,98,7,NULL,'UNKNOWN'),(99,'Einsteinium','Es',252,153,99,99,7,NULL,'UNKNOWN'),(100,'Fermium','Fm',257,157,100,100,7,NULL,'UNKNOWN'),(101,'Mendelevium','Md',258,157,101,101,7,NULL,'UNKNOWN'),(102,'Nobelium','No',259,157,102,102,7,NULL,'UNKNOWN'),(103,'Lawrencium','Lr',262,159,103,103,7,NULL,'UNKNOWN'),(104,'Rutherfordium','Rf',261,157,104,104,7,4,'UNKNOWN'),(105,'Dubnium','Db',262,157,105,105,7,5,'UNKNOWN'),(106,'Seaborgium','Sg',266,160,106,106,7,6,'UNKNOWN'),(107,'Bohrium','Bh',264,157,107,107,7,7,'UNKNOWN'),(108,'Hassium','Hs',267,159,108,108,7,8,'UNKNOWN'),(109,'Meitnerium','Mt',268,159,109,109,7,9,'UNKNOWN'),(110,'Darmstadtium ','Ds ',271,161,110,110,7,10,'UNKNOWN'),(111,'Roentgenium ','Rg ',272,161,111,111,7,11,'UNKNOWN'),(112,'Copernicium ','Cn ',285,173,112,112,7,12,'UNKNOWN'),(113,'Nihonium','Nh',284,171,113,113,7,13,'UNKNOWN'),(114,'Flerovium','Fl',289,175,114,114,7,14,'UNKNOWN'),(115,'Moscovium','Mc',288,173,115,115,7,15,'UNKNOWN'),(116,'Livermorium','Lv',292,176,116,116,7,16,'UNKNOWN'),(117,'Tennessine','Ts',295,178,117,117,7,17,'UNKNOWN'),(118,'Oganesson','Og',294,176,118,118,7,18,'UNKNOWN');
/*!40000 ALTER TABLE `ptable` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2022-03-27 19:43:31
