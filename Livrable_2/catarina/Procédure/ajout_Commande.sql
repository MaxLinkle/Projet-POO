DELIMITER $$
CREATE DEFINER=`admin`@`%` PROCEDURE `ajout_Commande`(IN `i_prix_ht` INT, IN `i_prix_tva` INT, IN `i_remise` INT, IN `date_liv` DATE, IN `date_emi` DATE, IN `date_paye` DATE, IN `date_sol` DATE, IN `i_id_adresse_de_livraison` INT, IN `i_id_adresse_facturation` INT, IN `i_id_cli` INT, IN `id_paye` INT)
BEGIN
DECLARE adresseliv_cli INT;
DECLARE adressefact_cli INT;
DECLARE paiement_cli INT;
DECLARE id_commande INT;

DECLARE EXIT HANDLER FOR SQLEXCEPTION
  BEGIN
    ROLLBACK;
  END;

SELECT ID_adresse_client INTO adresseliv_cli FROM Adresse_client WHERE adresse_client = i_id_adresse_de_livraison;

SELECT ID_adresse_client INTO adressefact_cli FROM Adresse_client WHERE adresse_client = i_id_adresse_facturation;

SELECT ID_paiement INTO paiement_cli FROM Paiement WHERE moyen_paiement = id_paye;

INSERT INTO Commande(ID_commande, reference, prix_ht, prix_tva, remise, date_livraison_prevue, date_emission, date_paiement, date_solde, ID_adresse_livraison, ID_adresse_facturation, ID_client, ID_paiement)
VALUES(NULL, "0", i_prix_ht, i_prix_tva, i_remise, date_liv, date_emi, date_paye, date_sol,adresseliv_cli, adressefact_cli, i_id_cli, paiement_cli);

SELECT LAST_INSERT_ID() INTO id_commande;
CALL generer_reference(i_id_cli, id_commande, @reference);

UPDATE Commande
SET reference = @reference
WHERE Commande.ID_commande = id_commande;

END$$
DELIMITER ;
