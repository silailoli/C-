-- MySQL dump 10.13  Distrib 8.0.28, for Win64 (x86_64)
--
-- Host: localhost    Database: usermsg
-- ------------------------------------------------------
-- Server version	8.0.28

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
-- Table structure for table `driver`
--

DROP TABLE IF EXISTS `driver`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `driver` (
  `iddriver` int NOT NULL AUTO_INCREMENT,
  `name` varchar(45) DEFAULT NULL,
  `carnumber` varchar(45) DEFAULT NULL,
  `telphone` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`iddriver`)
) ENGINE=InnoDB AUTO_INCREMENT=21 DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `driver`
--

LOCK TABLES `driver` WRITE;
/*!40000 ALTER TABLE `driver` DISABLE KEYS */;
INSERT INTO `driver` VALUES (1,'李华','湘A·2C7Z6','13257524271'),(2,'赵强华','湘A·3SQ94','15228653004'),(3,'刘丽','湘A·3H745','17428150354'),(4,'李伟东','湘A·1Q6Z1','13932507754'),(5,'陈述','湘A·3X947','19405345174'),(6,'丁德','湘A·4N41E','15407541718'),(7,'吴思林','湘A·7V655','19507145047'),(8,'李卡若','湘A·1Q666','14284714278'),(9,'魏娜','湘A·5WA14','14578685542'),(10,'阮当然','湘A·2M748','13587788524'),(11,'赵爱婷','湘A·3AE21','12758687258'),(12,'宋卫华','湘A·5R7M5','15207247844'),(13,'王志芳','湘A·0CC99','18305456741'),(14,'郭建立','湘A·0P12S','14407541718'),(15,'闫智胜','湘A·1E87F','15380178145'),(16,'郭卫东','湘A·6WZ41','13470417451'),(17,'鲁全福','湘A·2Q456','15807711784'),(18,'于光','湘A·1PJ45','17303450544'),(19,'马福平','湘A·3U1J1','18407540715'),(20,'贾隽仙','湘A·2G794','16308571847');
/*!40000 ALTER TABLE `driver` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `place`
--

DROP TABLE IF EXISTS `place`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `place` (
  `idplace` int NOT NULL AUTO_INCREMENT,
  `fromm` varchar(45) DEFAULT NULL,
  `tow` varchar(45) DEFAULT NULL,
  `lengthh` int DEFAULT NULL,
  PRIMARY KEY (`idplace`)
) ENGINE=InnoDB AUTO_INCREMENT=73 DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `place`
--

LOCK TABLES `place` WRITE;
/*!40000 ALTER TABLE `place` DISABLE KEYS */;
INSERT INTO `place` VALUES (1,'中南大学南校区','五一广场',8),(2,'五一广场','湘雅二医院',4),(3,'烈士公园','橘子洲',8),(4,'橘子洲','中南大学南校区',10),(5,'湖南大学','中南大学南校区',4),(6,'长沙南站','中南大学南校区',23),(7,'世界之窗','中南大学南校区',23),(8,'湘雅二医院','中南大学南校区',10),(9,'中南大学南校区','烈士公园',13),(10,'中南大学南校区','橘子洲',10),(11,'中南大学南校区','湖南大学',4),(12,'中南大学南校区','长沙南站',23),(13,'中南大学南校区','世界之窗',23),(14,'中南大学南校区','湘雅二医院',10),(15,'五一广场','中南大学南校区',8),(16,'五一广场','烈士公园',5),(17,'五一广场','橘子洲',3),(18,'五一广场','湖南大学',6),(19,'五一广场','长沙南站',16),(20,'五一广场','世界之窗',12),(21,'烈士公园','湘雅二医院',5),(22,'烈士公园','中南大学南校区',13),(23,'烈士公园','五一广场',5),(24,'烈士公园','湖南大学',10),(25,'烈士公园','长沙南站',16),(26,'烈士公园','世界之窗',10),(27,'橘子洲','五一广场',3),(28,'橘子洲','烈士公园',8),(29,'橘子洲','湖南大学',2),(30,'橘子洲','长沙南站',18),(31,'橘子洲','世界之窗',14),(32,'橘子洲','湘雅二医院',6),(33,'湖南大学','五一广场',6),(34,'湖南大学','烈士公园',10),(35,'湖南大学','橘子洲',2),(36,'湖南大学','长沙南站',17),(37,'湖南大学','世界之窗',16),(38,'湖南大学','湘雅二医院',7),(39,'长沙南站','五一广场',16),(40,'长沙南站','烈士公园',16),(41,'长沙南站','橘子洲',18),(42,'长沙南站','湖南大学',17),(43,'长沙南站','世界之窗',17),(44,'长沙南站','湘雅二医院',13),(45,'世界之窗','五一广场',12),(46,'世界之窗','烈士公园',10),(47,'世界之窗','橘子洲',14),(48,'世界之窗','湖南大学',16),(49,'世界之窗','长沙南站',17),(50,'世界之窗','湘雅二医院',11),(51,'湘雅二医院','五一广场',4),(52,'湘雅二医院','烈士公园',5),(53,'湘雅二医院','橘子洲',6),(54,'湘雅二医院','湖南大学',7),(55,'湘雅二医院','长沙南站',13),(56,'湘雅二医院','世界之窗',11),(57,'中南大学南校区','湖南省政府',11),(58,'湖南省政府','中南大学南校区',11),(59,'湖南省政府','湘雅二医院',10),(60,'湖南省政府','世界之窗',21),(61,'湖南省政府','五一广场',11),(62,'湖南省政府','烈士公园',15),(63,'湖南省政府','橘子洲',13),(64,'湖南省政府','湖南大学',12),(65,'湖南省政府','长沙南站',13),(66,'湘雅二医院','湖南省政府',10),(67,'世界之窗','湖南省政府',21),(68,'五一广场','湖南省政府',11),(69,'烈士公园','湖南省政府',15),(70,'橘子洲','湖南省政府',13),(71,'湖南大学','湖南省政府',12),(72,'长沙南站','湖南省政府',13);
/*!40000 ALTER TABLE `place` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `user`
--

DROP TABLE IF EXISTS `user`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `user` (
  `iduser` int NOT NULL AUTO_INCREMENT,
  `username` varchar(45) DEFAULT NULL,
  `password` varchar(45) DEFAULT NULL,
  `name` varchar(45) DEFAULT NULL,
  `age` int DEFAULT NULL,
  `man` tinyint DEFAULT NULL,
  `telephone` varchar(45) DEFAULT NULL,
  `cardnumber` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`iduser`)
) ENGINE=InnoDB AUTO_INCREMENT=26 DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `user`
--

LOCK TABLES `user` WRITE;
/*!40000 ALTER TABLE `user` DISABLE KEYS */;
INSERT INTO `user` VALUES (14,'root','liuxiangyu','liu',20,1,'15239928010','411402200209130518'),(22,'silence','liuxiangyu','刘翔宇',20,1,'13278882802','411402200208070518'),(25,'silence','LiuXiangyu','刘翔宇',21,1,'13278882801','411403200109130518');
/*!40000 ALTER TABLE `user` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `userquery`
--

DROP TABLE IF EXISTS `userquery`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `userquery` (
  `iduserquery` int NOT NULL AUTO_INCREMENT,
  `useid` int DEFAULT NULL,
  `fromm` varchar(45) DEFAULT NULL,
  `tow` varchar(45) DEFAULT NULL,
  `time` varchar(45) DEFAULT NULL,
  `ddid` int DEFAULT NULL,
  `statee` int DEFAULT NULL,
  PRIMARY KEY (`iduserquery`)
) ENGINE=InnoDB AUTO_INCREMENT=35 DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `userquery`
--

LOCK TABLES `userquery` WRITE;
/*!40000 ALTER TABLE `userquery` DISABLE KEYS */;
INSERT INTO `userquery` VALUES (15,14,'烈士公园','中南大学南校区','05月29日04时00分',3,-1),(16,14,'烈士公园','橘子洲','05月29日04时04分',9,0),(17,14,'烈士公园','中南大学南校区','05月29日14时00分',11,0),(19,14,'五一广场','橘子洲','06月01日20时17分',6,0),(20,14,'中南大学南校区','世界之窗','06月01日23时17分',8,0),(21,14,'中南大学南校区','橘子洲','06月02日14时12分',2,0),(22,14,'中南大学南校区','烈士公园','06月02日14时18分',4,0),(23,14,'中南大学南校区','五一广场','06月02日14时32分',4,0),(24,14,'中南大学南校区','长沙南站','06月03日16时31分',9,0),(25,22,'湖南省政府','长沙南站','06月05日09时30分',12,0),(26,22,'中南大学南校区','湘雅二医院','06月06日23时52分',17,0),(27,22,'中南大学南校区','世界之窗','06月23日20时47分',13,-1),(28,22,'中南大学南校区','湖南大学','06月22日19时50分',15,0),(29,22,'湘雅二医院','五一广场','06月25日14时45分',2,-1),(32,14,'中南大学南校区','五一广场','06月24日17时11分',1,1),(33,22,'橘子洲','长沙南站','06月26日22时43分',11,-1),(34,22,'中南大学南校区','湖南省政府','06月24日20时43分',10,1);
/*!40000 ALTER TABLE `userquery` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Dumping events for database 'usermsg'
--

--
-- Dumping routines for database 'usermsg'
--
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2022-06-25 18:03:40
