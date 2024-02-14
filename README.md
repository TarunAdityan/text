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




Text.Combine(List.Select(Text.ToCodePoints([Item Transaction Description]), each Character.IsDigit(_)), "")

