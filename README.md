if [Document Date] <> null then 
    let 
        year = Date.Year([Document Date]),
        month = Date.Month([Document Date]),
        quarter = 
            if month >= 1 and month <= 3 then "Q1" 
            else if month >= 4 and month <= 6 then "Q2" 
            else if month >= 7 and month <= 9 then "Q3" 
            else if month >= 10 and month <= 12 then "Q4" 
            else null 
    in 
        quarter & " " & Text.From(year)
else if [Item Transaction Description] <> null then 
    let 
        numericPart = Text.Middle([Item Transaction Description], 0, Text.PositionOf([Item Transaction Description], "/", Occurrence.First())),
        month = if numericPart <> null then Number.From(numericPart) else null,
        year = Date.Year([Period]),
        quarter = 
            if month <> null and month >= 1 and month <= 3 then "Q1" 
            else if month <> null and month >= 4 and month <= 6 then "Q2" 
            else if month <> null and month >= 7 and month <= 9 then "Q3" 
            else if month <> null and month >= 10 and month <= 12 then "Q4" 
            else null 
    in 
        quarter & " " & Text.From(year)
else if [Period] <> null then 
    let 
        year = Date.Year([Period]),
        month = Date.Month([Period]),
        quarter = 
            if month >= 1 and month <= 3 then "Q1" 
            else if month >= 4 and month <= 6 then "Q2" 
            else if month >= 7 and month <= 9 then "Q3" 
            else if month >= 10 and month <= 12 then "Q4" 
            else null 
    in 
        quarter & " " & Text.From(year)
else 
    null





\b\d{1,2}/\d{1,2}/\d{4}\b|\b\d{1,2}/\d{4}\b

= if [Item Transaction Description] = null or Text.Length([Item Transaction Description]) = 0 then null
else let
    LastDateStartPosition = List.Max({Text.PositionOf([Item Transaction Description], "Q1"), 
                                       Text.PositionOf([Item Transaction Description], "Q2"), 
                                       Text.PositionOf([Item Transaction Description], "Q3"), 
                                       Text.PositionOf([Item Transaction Description], "Q4"), 
                                       Text.PositionOf([Item Transaction Description], "Jan"), 
                                       Text.PositionOf([Item Transaction Description], "Feb"), 
                                       Text.PositionOf([Item Transaction Description], "Mar"), 
                                       Text.PositionOf([Item Transaction Description], "Apr"), 
                                       Text.PositionOf([Item Transaction Description], "May"), 
                                       Text.PositionOf([Item Transaction Description], "Jun"), 
                                       Text.PositionOf([Item Transaction Description], "Jul"), 
                                       Text.PositionOf([Item Transaction Description], "Aug"), 
                                       Text.PositionOf([Item Transaction Description], "Sep"), 
                                       Text.PositionOf([Item Transaction Description], "Oct"), 
                                       Text.PositionOf([Item Transaction Description], "Nov"), 
                                       Text.PositionOf([Item Transaction Description], "Dec")}),
    LastDate = Text.Middle([Item Transaction Description], LastDateStartPosition, Text.Length([Item Transaction Description])),
    Year = Text.Middle(LastDate, Text.PositionOf(LastDate, " ", Occurrence.Last) + 1, 4),
    Month = Text.Middle(LastDate, Text.PositionOf(LastDate, " ", Occurrence.Last) - 3, 3),
    Quarter = if Month = "Jan" or Month = "Feb" or Month = "Mar" then "Q1 " & Year
              else if Month = "Apr" or Month = "May" or Month = "Jun" then "Q2 " & Year
              else if Month = "Jul" or Month = "Aug" or Month = "Sep" then "Q3 " & Year
              else if Month = "Oct" or Month = "Nov" or Month = "Dec" then "Q4 " & Year
              else "Quarter and year not found"
in
    Quarter





