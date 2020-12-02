DELIMITER $$
CREATE DEFINER=`admin`@`%` PROCEDURE `ajoutUpdate_Adresse_client`(IN `i_id_client` INT, IN `i_adresse` VARCHAR(50), IN `i_ville` INT(20), IN `i_type_adresse` INT(25))
BEGIN
  DECLARE ville_cli INT;
  DECLARE type_cli INT;

  DECLARE EXIT HANDLER FOR SQLEXCEPTION
  BEGIN
    ROLLBACK;
  END;

  SELECT ID_ville INTO ville_cli FROM Ville WHERE ville = i_ville;
  SELECT ID_type_adresse INTO type_cli FROM Type_adresse WHERE type_adresse = i_type_adresse;

IF i_adresse = adresse_client THEN
  UPDATE Adresse_client 
  SET ID_type_adresse = 3
  WHERE ID_client = i_id_client;
  
ELSE
  INSERT INTO Adresse_client (adresse_client,ID_client, ID_ville, ID_type_adresse)
  VALUES (i_adresse, i_id_client, ville_cli, type_cli);
END IF;
END$$
DELIMITER ;