USE DemoDB;


CREATE TABLE CityDB
(
    [FromCity] [NVARCHAR](20),
    [ToCity] [NVARCHAR](20),
    [Distance(KM)] INT
)
SELECT *
FROM CityDB;
TRUNCATE TABLE CityDB;

-- INSERT 
--     INTO CityDB(FromCity,ToCity,[Distance(KM)])
--     VALUES
--         ('Chhindwara' , 'Seoni',70),
--         ('Seoni','Chhindwara',70),-
--         ('Nagpur','Mumbai',400),
--         ('Mumbai','Nagpur',400);

SELECT
    C1.FromCity,
    C1.[ToCity] ,
    C1.[Distance(KM)]
FROM
    CityDB C1
    JOIN CityDB C2
    on C1.FromCity=C2.[ToCity] and C1.ToCity=C2.[FromCity] 