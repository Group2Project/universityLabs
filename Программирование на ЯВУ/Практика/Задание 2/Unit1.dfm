object Form1: TForm1
  Left = 179
  Top = 156
  Width = 514
  Height = 350
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 24
    Top = 16
    Width = 257
    Height = 129
    Caption = #1056#1072#1079#1084#1077#1088#1099' '#1084#1072#1090#1088#1080#1094#1099':'
    TabOrder = 0
    object Label1: TLabel
      Left = 24
      Top = 32
      Width = 39
      Height = 13
      Caption = #1057#1090#1088#1086#1082#1080':'
    end
    object Label2: TLabel
      Left = 24
      Top = 64
      Width = 44
      Height = 13
      Caption = #1057#1090#1086#1083#1073#1094#1099
    end
    object CSpinEdit1: TCSpinEdit
      Left = 80
      Top = 24
      Width = 121
      Height = 22
      TabOrder = 0
    end
    object CSpinEdit2: TCSpinEdit
      Left = 80
      Top = 56
      Width = 121
      Height = 22
      TabOrder = 1
    end
    object Button1: TButton
      Left = 80
      Top = 88
      Width = 75
      Height = 25
      Caption = #1042#1074#1086#1076
      TabOrder = 2
      OnClick = Button1Click
    end
  end
  object StringGrid1: TStringGrid
    Left = 24
    Top = 160
    Width = 273
    Height = 89
    ColCount = 4
    FixedCols = 0
    RowCount = 3
    FixedRows = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing, goTabs]
    TabOrder = 1
    Visible = False
  end
  object Button2: TButton
    Left = 304
    Top = 24
    Width = 75
    Height = 25
    Caption = #1042#1074#1086#1076
    TabOrder = 2
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 304
    Top = 56
    Width = 75
    Height = 25
    Caption = #1057#1073#1088#1086#1089
    TabOrder = 3
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 304
    Top = 88
    Width = 75
    Height = 25
    Caption = #1042#1099#1093#1086#1076
    TabOrder = 4
    OnClick = Button4Click
  end
end
