= if Number.IsNaN(Number.From([Document Date])) then
      if Text.Contains([Item Desc], "/") then
          let month = Number.From(Text.Middle([Item Desc], Text.PositionOf([Item Desc], "/") - 2, 2)) in
          if month >= 1 and month <= 3 then "Q1"
          else if month >= 4 and month <= 6 then "Q2"
          else if month >= 7 and month <= 9 then "Q3"
          else if month >= 10 and month <= 12 then "Q4"
          else null
      else if Number.IsNaN([Period]) then null
      else [Period]
else
    let month = Date.Month([Document Date]) in
    if month >= 1 and month <= 3 then "Q1"
    else if month >= 4 and month <= 6 then "Q2"
    else if month >= 7 and month <= 9 then "Q3"
    else if month >= 10 and month <= 12 then "Q4"
    else null
