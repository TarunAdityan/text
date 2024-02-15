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
    DateKeywords = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec", "Q1", "Q2", "Q3", "Q4"},
    Dates = List.Buffer(
        List.Select(
            List.Transform(
                DateKeywords,
                each 
                    if Text.Contains(Description, _) then 
                        let
                            DateString = Text.Range(Description, Text.PositionOf(Description, _, Occurrence.Last), Text.Length(Description)),
                            Date = Text.Range(DateString, Text.PositionOf(DateString, " "), 11)
                        in
                            if Text.Contains(Date, "to") then
                                let
                                    DateParts = Text.Split(Date, "to"),
                                    LastDate = List.Last(Text.Split(DateParts{1}, " "))
                                in
                                    LastDate
                            else
                                Date
                    else null
            ),
            each _ <> null
        )
    ),
    SortedDates = List.Sort(Dates, Order.Descending),
    SelectedDate = List.First(SortedDates),
    Year = Text.Middle(SelectedDate, Text.PositionOf(SelectedDate, " ") + 1, 4),
    Month = Text.Middle(SelectedDate, 1, 3),
    Quarter = 
        if Number.FromText(Text.Middle(Month, 1, 2)) <= 3 then "Q1 " & Year
        else if Number.FromText(Text.Middle(Month, 1, 2)) <= 6 then "Q2 " & Year
        else if Number.FromText(Text.Middle(Month, 1, 2)) <= 9 then "Q3 " & Year
        else "Q4 " & Year
in
    Quarter





tttttttttttttttttttttt

= if [Document Date] <> null then 
    let 
        year = Date.Year([Document Date]), 
        month = Date.Month([Document Date]), 
        quarter = if month >= 1 and month <= 3 then "Q1" else if month >= 4 and month <= 6 then "Q2" else if month >= 7 and month <= 9 then "Q3" else if month >= 10 and month <= 12 then "Q4" else null 
    in 
        quarter & " " & Text.From(year) 
else 
    if [Customitds] <> null then 
        let
            CustomitdsText = Text.Trim([Customitds]),
            QuarterPart = Text.FirstN(CustomitdsText, Text.PositionOf(CustomitdsText, " ", Occurrence.First())),
            YearPart = Text.Middle(CustomitdsText, Text.PositionOf(CustomitdsText, " ", Occurrence.First()) + 1, 4),
            YearNumber = if Text.Length(YearPart) = 2 then "20" & YearPart else YearPart
        in
            QuarterPart & " " & YearNumber
    else 
        if [Period] <> null then 
            let 
                year = Date.Year([Period]), 
                month = Date.Month([Period]), 
                quarter = if month >= 1 and month <= 3 then "Q1" else if month >= 4 and month <= 6 then "Q2" else if month >= 7 and month <= 9 then "Q3" else if month >= 10 and month <= 12 then "Q4" else null 
            in 
                quarter & " " & Text.From(year) 
        else 
            null

