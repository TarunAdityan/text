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
    if [ITD] <> null then 
        let 
            monthIndex = 
                if Text.Contains([ITD], "Jan") then Text.PositionOf([ITD], "Jan") + 4
                else if Text.Contains([ITD], "Feb") then Text.PositionOf([ITD], "Feb") + 4
                else if Text.Contains([ITD], "Mar") then Text.PositionOf([ITD], "Mar") + 4
                else if Text.Contains([ITD], "Apr") then Text.PositionOf([ITD], "Apr") + 4
                else if Text.Contains([ITD], "May") then Text.PositionOf([ITD], "May") + 4
                else if Text.Contains([ITD], "Jun") then Text.PositionOf([ITD], "Jun") + 4
                else if Text.Contains([ITD], "Jul") then Text.PositionOf([ITD], "Jul") + 4
                else if Text.Contains([ITD], "Aug") then Text.PositionOf([ITD], "Aug") + 4
                else if Text.Contains([ITD], "Sep") then Text.PositionOf([ITD], "Sep") + 4
                else if Text.Contains([ITD], "Oct") then Text.PositionOf([ITD], "Oct") + 4
                else if Text.Contains([ITD], "Nov") then Text.PositionOf([ITD], "Nov") + 4
                else if Text.Contains([ITD], "Dec") then Text.PositionOf([ITD], "Dec") + 4
                else null,
            yearIndex = Text.PositionOf([ITD], " ", Occurrence.Last()) + 1,
            month = Text.Middle([ITD], monthIndex, 3),
            year = Text.Middle([ITD], yearIndex, 4)
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
