= if [Document Date] <> null then 
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
else 
    if [Item Transaction Description] <> null then 
        let 
            monthIndex = 
                if Text.Contains([Item Transaction Description], "Jan") then Text.PositionOf([Item Transaction Description], "Jan") + 4
                else if Text.Contains([Item Transaction Description], "Feb") then Text.PositionOf([Item Transaction Description], "Feb") + 4
                else if Text.Contains([Item Transaction Description], "Mar") then Text.PositionOf([Item Transaction Description], "Mar") + 4
                else if Text.Contains([Item Transaction Description], "Apr") then Text.PositionOf([Item Transaction Description], "Apr") + 4
                else if Text.Contains([Item Transaction Description], "May") then Text.PositionOf([Item Transaction Description], "May") + 4
                else if Text.Contains([Item Transaction Description], "Jun") then Text.PositionOf([Item Transaction Description], "Jun") + 4
                else if Text.Contains([Item Transaction Description], "Jul") then Text.PositionOf([Item Transaction Description], "Jul") + 4
                else if Text.Contains([Item Transaction Description], "Aug") then Text.PositionOf([Item Transaction Description], "Aug") + 4
                else if Text.Contains([Item Transaction Description], "Sep") then Text.PositionOf([Item Transaction Description], "Sep") + 4
                else if Text.Contains([Item Transaction Description], "Oct") then Text.PositionOf([Item Transaction Description], "Oct") + 4
                else if Text.Contains([Item Transaction Description], "Nov") then Text.PositionOf([Item Transaction Description], "Nov") + 4
                else if Text.Contains([Item Transaction Description], "Dec") then Text.PositionOf([Item Transaction Description], "Dec") + 4
                else null,
            yearIndex = Text.PositionOf([Item Transaction Description], " ", Occurrence.Last()) + 1,
            month = Text.Middle([Item Transaction Description], monthIndex, 3),
            year = Text.Middle([Item Transaction Description], yearIndex, 4)
        in 
            month & " " & year
    else 
        if [Period] <> null then 
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
