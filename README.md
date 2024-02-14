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


= if [Item Transaction Description] = null then null
else if Text.Contains([Item Transaction Description], "Q1") then "Q1 " & Text.Middle([Item Transaction Description], Text.PositionOf([Item Transaction Description], "Q1") + 3, 4)
else if Text.Contains([Item Transaction Description], "Q2") then "Q2 " & Text.Middle([Item Transaction Description], Text.PositionOf([Item Transaction Description], "Q2") + 3, 4)
else if Text.Contains([Item Transaction Description], "Q3") then "Q3 " & Text.Middle([Item Transaction Description], Text.PositionOf([Item Transaction Description], "Q3") + 3, 4)
else if Text.Contains([Item Transaction Description], "Q4") then "Q4 " & Text.Middle([Item Transaction Description], Text.PositionOf([Item Transaction Description], "Q4") + 3, 4)
else if Text.Contains([Item Transaction Description], "Jan") then "Q1 " & Text.Middle([Item Transaction Description], Text.PositionOf([Item Transaction Description], "Jan") + 4, 4)
else if Text.Contains([Item Transaction Description], "Feb") then "Q1 " & Text.Middle([Item Transaction Description], Text.PositionOf([Item Transaction Description], "Feb") + 4, 4)
else if Text.Contains([Item Transaction Description], "Mar") then "Q1 " & Text.Middle([Item Transaction Description], Text.PositionOf([Item Transaction Description], "Mar") + 4, 4)
else if Text.Contains([Item Transaction Description], "Apr") then "Q2 " & Text.Middle([Item Transaction Description], Text.PositionOf([Item Transaction Description], "Apr") + 4, 4)
else if Text.Contains([Item Transaction Description], "May") then "Q2 " & Text.Middle([Item Transaction Description], Text.PositionOf([Item Transaction Description], "May") + 4, 4)
else if Text.Contains([Item Transaction Description], "Jun") then "Q2 " & Text.Middle([Item Transaction Description], Text.PositionOf([Item Transaction Description], "Jun") + 4, 4)
else if Text.Contains([Item Transaction Description], "Jul") then "Q3 " & Text.Middle([Item Transaction Description], Text.PositionOf([Item Transaction Description], "Jul") + 4, 4)
else if Text.Contains([Item Transaction Description], "Aug") then "Q3 " & Text.Middle([Item Transaction Description], Text.PositionOf([Item Transaction Description], "Aug") + 4, 4)
else if Text.Contains([Item Transaction Description], "Sep") then "Q3 " & Text.Middle([Item Transaction Description], Text.PositionOf([Item Transaction Description], "Sep") + 4, 4)
else if Text.Contains([Item Transaction Description], "Oct") then "Q4 " & Text.Middle([Item Transaction Description], Text.PositionOf([Item Transaction Description], "Oct") + 4, 4)
else if Text.Contains([Item Transaction Description], "Nov") then "Q4 " & Text.Middle([Item Transaction Description], Text.PositionOf([Item Transaction Description], "Nov") + 4, 4)
else if Text.Contains([Item Transaction Description], "Dec") then "Q4 " & Text.Middle([Item Transaction Description], Text.PositionOf([Item Transaction Description], "Dec") + 4, 4)
else null


ttttttttttt


let
    Description = [Item Transaction Description],
    Dates = List.Sort(
        List.Transform(
            List.Distinct(
                List.Select(
                    List.Buffer({{"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"}} & {"Q1", "Q2", "Q3", "Q4"}), 
                    (keyword) => Text.Contains(Description, keyword)
                )
            ),
            (keyword) => 
                let
                    keywordIndex = Text.PositionOf(Description, keyword, Occurrence.Last),
                    dateStartIndex = keywordIndex + Text.Length(keyword) + 1,
                    dateEndIndex = if Text.PositionOf(Description, " ", dateStartIndex) <> -1 then Text.PositionOf(Description, " ", dateStartIndex) else Text.Length(Description),
                    date = Text.Middle(Description, dateStartIndex, dateEndIndex - dateStartIndex)
                in
                    if Text.Contains(date, "to") then
                        let
                            dateParts = Text.Split(date, " to "),
                            lastDateIndex = List.Max({Text.PositionOf(dateParts{0}, " ", Occurrence.Last), Text.PositionOf(dateParts{1}, " ", Occurrence.Last)}),
                            lastDate = Text.Middle(dateParts{0}, lastDateIndex, Text.Length(dateParts{0}))
                        in
                            lastDate
                    else
                        date
        )
    ),
    Year = Text.Middle(Dates{List.Count(Dates) - 1}, Text.PositionOf(Dates{List.Count(Dates) - 1}, " ", Occurrence.Last) + 1, 4),
    Month = Text.Middle(Dates{List.Count(Dates) - 1}, Text.PositionOf(Dates{List.Count(Dates) - 1}, " ", Occurrence.Last) - 3, 3),
    Quarter = if Month = "Jan" or Month = "Feb" or Month = "Mar" then "Q1 " & Year
              else if Month = "Apr" or Month = "May" or Month = "Jun" then "Q2 " & Year
              else if Month = "Jul" or Month = "Aug" or Month = "Sep" then "Q3 " & Year
              else "Q4 " & Year
in
    Quarter




tttttttttttttttttttttt
