= if Text.Contains([Item Transaction Description], "Q1") then "Q1 " & Text.Middle([Item Transaction Description], Text.PositionOf([Item Transaction Description], "Q1") + 3, 4)
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
else "Quarter and year not found"











= if [Document Date] <> null then
    let month = Date.Month([Document Date]) in
    Text.From(
        if month >= 1 and month <= 3 then "Q1"
        else if month >= 4 and month <= 6 then "Q2"
        else if month >= 7 and month <= 9 then "Q3"
        else if month >= 10 and month <= 12 then "Q4"
        else null
    )
else if [Item Desc] <> null then
    let numericPart = Text.StartWhile([Item Desc], each Text.From(_) >= "0" and Text.From(_) <= "9") in
    let month = if Number.FromOrNull(numericPart) <> null then Number.From(numericPart) else null in
    Text.From(
        if month >= 1 and month <= 3 then "Q1"
        else if month >= 4 and month <= 6 then "Q2"
        else if month >= 7 and month <= 9 then "Q3"
        else if month >= 10 and month <= 12 then "Q4"
        else null
    )
else if [Period] <> null then
    let month = Date.Month([Period]) in
    Text.From(
        if month >= 1 and month <= 3 then "Q1"
        else if month >= 4 and month <= 6 then "Q2"
        else if month >= 7 and month <= 9 then "Q3"
        else if month >= 10 and month <= 12 then "Q4"
        else null
    )
else null
0000000008800079096066606976907696096969869-86-06

    = if [Document Date] <> null then
    let month = Date.Month([Document Date]) in
    Text.From(
        if month >= 1 and month <= 3 then "Q1"
        else if month >= 4 and month <= 6 then "Q2"
        else if month >= 7 and month <= 9 then "Q3"
        else if month >= 10 and month <= 12 then "Q4"
        else null
    )
else if [Item Desc] <> null then
    let numericPart = Text.Middle([Item Desc], 0, Text.PositionOf([Item Desc], "/", Occurrence.First())) in
    let month = if Number.FromOrNull(numericPart) <> null then Number.From(numericPart) else null in
    Text.From(
        if month >= 1 and month <= 3 then "Q1"
        else if month >= 4 and month <= 6 then "Q2"
        else if month >= 7 and month <= 9 then "Q3"
        else if month >= 10 and month <= 12 then "Q4"
        else null
    )
else if [Period] <> null then
    let month = Date.Month([Period]) in
    Text.From(
        if month >= 1 and month <= 3 then "Q1"
        else if month >= 4 and month <= 6 then "Q2"
        else if month >= 7 and month <= 9 then "Q3"
        else if month >= 10 and month <= 12 then "Q4"
        else null
    )
else null
