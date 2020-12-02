DELIMITER |
DROP FUNCTION  IF EXISTS `AjoutIndividus` |
CREATE FUNCTION `AjoutIndividus`(`CliPer` BOOLEAN, `PNom` VARCHAR(50), `PPrenom` VARCHAR(50), `PDate` DATE, `PSNom` VARCHAR(50), `PSPrenom` VARCHAR(50)) 
RETURNS INT UNSIGNED
BEGIN
    DECLARE Tab VARCHAR(50);
    DECLARE Sup INT;
    DECLARE retour INT;
    
    IF CliPer THEN

        IF PDate = NULL OR YEAR(PDATE) = 0
           THEN SET PDATE = NULL;
        END IF;

        INSERT INTO `Client`(nom,prenom,date_naissance) VALUES (PNom,PPrenom,PDate);

    ELSE

        
        IF PDate = NULL OR YEAR(PDATE) = 0
            THEN RETURN NULL;
        END IF;


        IF (SELECT COUNT(*) FROM Personnel WHERE nom = PSNom AND prenom = PSPrenom) != 1 THEN
            SET Sup = NULL;
        ELSE 
            SELECT ID_personnel INTO Sup FROM Personnel WHERE nom = PSNom AND prenom = PSPrenom;
        END IF;
        
        INSERT INTO `Personnel`(nom,prenom,date_embauche,ID_superieur) VALUES (PNom,PPrenom,PDate,Sup);

            
            
    END IF;
    
    RETURN LAST_INSERT_ID();
    

END |