-- MySQL dump 10.13  Distrib 5.5.62, for Linux (x86_64)
--
-- Host: localhost    Database: blink
-- ------------------------------------------------------
-- Server version	5.5.62-log

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `INFO`
--

DROP TABLE IF EXISTS `INFO`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `INFO` (
  `ID` int(11) NOT NULL AUTO_INCREMENT,
  `CLIENT` varchar(255) NOT NULL,
  `SERVER` varchar(255) NOT NULL,
  `STATUS` int(11) NOT NULL DEFAULT '1',
  `KEY` varchar(512) NOT NULL,
  `CREATE` timestamp NULL DEFAULT NULL ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB AUTO_INCREMENT=34 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `INFO`
--

LOCK TABLES `INFO` WRITE;
/*!40000 ALTER TABLE `INFO` DISABLE KEYS */;
INSERT INTO `INFO` VALUES (4,'lisuqing','lizhan',1,'QLYo4K3s3o2oSlW5RJ378zYA',NULL),(27,'lisuqing','lizhan',1,'6MCEH01koqA7dZQloqbkvB82',NULL),(28,'lisuqing','lizhan',1,'Idh4qDr82yfJ54763P3pJOZh',NULL),(29,'lisuqing','lizhan',1,'Ew7Go932955G7TWvjMup8f1X',NULL),(30,'lisuqing','lizhan',1,'T5WnTkO4NwqHkqtrhp0MJ898',NULL),(31,'lisuqing','lizhan',1,'1RI5eZG4ZI7eV7Twl37PG9xj',NULL),(32,'lisuqing','lizhan',1,'ZLL0kVCubgDZ7368676vMwKR',NULL),(33,'lisuqing','lizhan',1,'43337sHK3UaS14jRr7toQi6d',NULL);
/*!40000 ALTER TABLE `INFO` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `KEYID`
--

DROP TABLE IF EXISTS `KEYID`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `KEYID` (
  `KEYID` int(11) NOT NULL,
  PRIMARY KEY (`KEYID`) USING BTREE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `KEYID`
--

LOCK TABLES `KEYID` WRITE;
/*!40000 ALTER TABLE `KEYID` DISABLE KEYS */;
INSERT INTO `KEYID` VALUES (34);
/*!40000 ALTER TABLE `KEYID` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `NODE`
--

DROP TABLE IF EXISTS `NODE`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `NODE` (
  `ID` varchar(255) NOT NULL,
  `NAME` varchar(255) NOT NULL,
  `DESC` varchar(255) DEFAULT NULL,
  `STATUS` int(11) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `NODE`
--

LOCK TABLES `NODE` WRITE;
/*!40000 ALTER TABLE `NODE` DISABLE KEYS */;
/*!40000 ALTER TABLE `NODE` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2020-05-18 19:57:43
