object Form1: TForm1
  Left = 201
  Top = 147
  Width = 725
  Height = 191
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 40
    Top = 32
    Width = 85
    Height = 13
    Caption = #1063#1080#1089#1083#1086' '#1089#1080#1084#1074#1086#1083#1086#1074
  end
  object CSpinEdit1: TCSpinEdit
    Left = 136
    Top = 24
    Width = 121
    Height = 22
    TabOrder = 0
    Value = 10
  end
  object StringGrid1: TStringGrid
    Left = 24
    Top = 64
    Width = 657
    Height = 33
    ColCount = 10
    FixedCols = 0
    RowCount = 1
    FixedRows = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing, goTabs]
    TabOrder = 1
  end
  object Button1: TButton
    Left = 272
    Top = 16
    Width = 75
    Height = 25
    Caption = #1042#1074#1086#1076
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 24
    Top = 104
    Width = 81
    Height = 33
    Caption = #1055#1088#1086#1074#1077#1088#1082#1072
    TabOrder = 3
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 120
    Top = 104
    Width = 81
    Height = 33
    Caption = #1057#1073#1088#1086#1089
    TabOrder = 4
    OnClick = Button3Click
  end
end
