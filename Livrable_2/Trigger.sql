DELIMITER |
CREATE TRIGGER delete_Personnel BEFORE DELETE
ON Personnel FOR EACH ROW
BEGIN
  DELETE FROM Adresse_personnel WHERE (ID_personnel = OLD.ID_personnel);
END |


CREATE TRIGGER delete_Client BEFORE DELETE
ON Client FOR EACH ROW
BEGIN
  DELETE FROM Adresse_client WHERE (ID_client = OLD.ID_client);
END |

CREATE TRIGGER TCommande BEFORE DELETE
ON Commande FOR EACH ROW
BEGIN
  DELETE FROM Fournir WHERE (ID_commande = old.commande);
END |

CREATE TRIGGER update_Catalogue AFTER UPDATE
ON Catalogue FOR EACH ROW
BEGIN
  DROP VIEW IF EXISTS Catalogue_actif;

  CREATE VIEW Catalogue_actif AS
  SELECT ID_catalogue_actif, nom, reference, prix_ht, taux_tva, stock, seuil_reapprovisionnement
  FROM Catalogue
  WHERE actif = true;
END |
DELIMITER;
