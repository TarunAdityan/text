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
