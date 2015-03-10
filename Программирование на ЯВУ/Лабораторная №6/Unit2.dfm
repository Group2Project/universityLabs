object Form2: TForm2
  Left = 144
  Top = 166
  Width = 396
  Height = 248
  Caption = 'Form2'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Exit: TButton
    Left = 272
    Top = 160
    Width = 81
    Height = 33
    Caption = #1042#1099#1093#1086#1076
    TabOrder = 0
    OnClick = ExitClick
  end
  object StringGrid1: TStringGrid
    Left = 24
    Top = 16
    Width = 329
    Height = 129
    FixedCols = 0
    FixedRows = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing, goTabs]
    TabOrder = 1
  end
  object Clear: TButton
    Left = 152
    Top = 160
    Width = 81
    Height = 33
    Caption = #1057#1073#1088#1086#1089
    TabOrder = 2
    OnClick = ClearClick
  end
  object Enter: TButton
    Left = 24
    Top = 160
    Width = 81
    Height = 33
    Caption = #1042#1074#1086#1076
    TabOrder = 3
    OnClick = EnterClick
  end
end
