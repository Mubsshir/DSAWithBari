--  Question 1 Solution ----------------------
DECLARE @mins VARCHAR(30)='17362',@FTime as time;

-- SELECT CONVERT(datetime, DATEADD(MINUTE, 173620, GETDATE())) ;

set @FTime=CAST(CONVERT(time, DATEADD(MINUTE, CAST(@mins as INT), 0)) as NVARCHAR(8));
select @FTime
declare @FHour INT=datepart(hour,@FTime);
SELECT
    CASE WHEN @FHour%24=0 
	THEN CONCAT(@FHour/24,':',@FTime)
	ELSE CONCAT('00',':',@FTime)
	END as [Answer];

-- ---------------------

DECLARE @NewTime DATETIME= CONVERT(datetime, DATEADD(MINUTE, 173620, GETDATE()));

select (173620/60)/24;
select DATEDIFF(MINUTE,GETDATE(),@NewTime);

SELECT CONVERT(datetime, DATEADD(MINUTE, 1440, 0))

DECLARE @Minutes INT = 8262;

SELECT
    CONVERT(VARCHAR(2), (@Minutes / 1440)) + ':' +
    RIGHT('0' + CONVERT(VARCHAR(2), (@Minutes % 1440) / 60), 2) + ':' +
    RIGHT('0' + CONVERT(VARCHAR(2), (@Minutes % 60)), 2) AS DD_HH_SS;


DECLARE @Second int = 495720;

SELECT
    -- first convert seconds into days
    CONVERT(VARCHAR(2), (@Second / 86400)) + ':' +	
	-- then convert remaing second into hours
    RIGHT('0' + CONVERT(VARCHAR(2), (@Second % 86400) /3600), 2) + ':' +
    RIGHT('0' + CONVERT(VARCHAR(2), (@Second % 86400) % 3600)/60, 2)+':'+
	RIGHT('0' + CONVERT(VARCHAR(2), (@Second % 86400) % 3600)%60, 2)
	AS [DD:HH:mm:ss];
GO

DECLARE @Str NVARCHAR(MAX) = 'hello mom how are u';
DECLARE @Result NVARCHAR(MAX) = LOWER(@Str);
DECLARE @Pos INT = 1;

WHILE CHARINDEX(' ', @Result, @Pos) > 0
BEGIN
    SET @Pos = CHARINDEX(' ', @Result, @Pos) + 1;
    SET @Result = STUFF(@Result, @Pos, 1, UPPER(SUBSTRING(@Result, @Pos, 1)));
END

SET @Result = UPPER(LEFT(@Result, 1)) + SUBSTRING(@Result, 2, LEN(@Result));

SELECT @Result AS ProperCase;


