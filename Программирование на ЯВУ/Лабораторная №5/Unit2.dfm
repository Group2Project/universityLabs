object Exercise1: TExercise1
  Left = 238
  Top = 228
  Width = 722
  Height = 157
  Caption = #1047#1072#1076#1072#1085#1080#1077' 1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 152
    Top = 80
    Width = 55
    Height = 13
    Caption = #1056#1077#1079#1091#1083#1100#1090#1072#1090':'
  end
  object Result: TLabel
    Left = 211
    Top = 80
    Width = 3
    Height = 13
  end
  object Exit: TButton
    Left = 576
    Top = 64
    Width = 105
    Height = 33
    Caption = #1042#1099#1093#1086#1076
    TabOrder = 0
    OnClick = ExitClick
  end
  object Clear: TButton
    Left = 456
    Top = 64
    Width = 113
    Height = 33
    Caption = #1057#1073#1088#1086#1089
    TabOrder = 2
    OnClick = ClearClick
  end
  object StringGrid1: TStringGrid
    Left = 24
    Top = 16
    Width = 657
    Height = 33
    ColCount = 10
    FixedCols = 0
    RowCount = 1
    FixedRows = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing, goTabs]
    TabOrder = 3
  end
  object Button1: TButton
    Left = 24
    Top = 64
    Width = 105
    Height = 33
    Caption = #1042#1099#1095#1080#1089#1083#1080#1090#1100
    TabOrder = 1
    OnClick = CalculateClick
  end
end
