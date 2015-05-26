object Form1: TForm1
  Left = 125
  Top = 141
  Width = 745
  Height = 417
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
    Left = 16
    Top = 16
    Width = 169
    Height = 105
    Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1091#1079#1083#1086#1074':'
    TabOrder = 0
    object CSpinEdit1: TCSpinEdit
      Left = 16
      Top = 27
      Width = 129
      Height = 22
      TabOrder = 0
    end
    object Button1: TButton
      Left = 40
      Top = 64
      Width = 75
      Height = 25
      Caption = #1042#1074#1086#1076
      TabOrder = 1
      OnClick = Button1Click
    end
  end
  object GroupBox2: TGroupBox
    Left = 16
    Top = 136
    Width = 209
    Height = 153
    Caption = #1055#1072#1088#1072#1084#1077#1090#1088#1099
    TabOrder = 1
    Visible = False
    object Label1: TLabel
      Left = 16
      Top = 32
      Width = 40
      Height = 13
      Caption = #1053#1072#1095#1072#1083#1086':'
    end
    object Label2: TLabel
      Left = 16
      Top = 72
      Width = 34
      Height = 13
      Caption = #1050#1086#1085#1077#1094':'
    end
    object Button2: TButton
      Left = 56
      Top = 104
      Width = 75
      Height = 25
      Caption = #1053#1072#1081#1090#1080':'
      TabOrder = 0
      OnClick = Button2Click
    end
    object CSpinEdit2: TCSpinEdit
      Left = 64
      Top = 24
      Width = 121
      Height = 22
      TabOrder = 1
    end
    object CSpinEdit3: TCSpinEdit
      Left = 64
      Top = 64
      Width = 121
      Height = 22
      TabOrder = 2
    end
  end
  object StringGrid1: TStringGrid
    Left = 272
    Top = 24
    Width = 433
    Height = 313
    FixedCols = 0
    FixedRows = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing, goTabs]
    TabOrder = 2
    Visible = False
  end
  object Button3: TButton
    Left = 16
    Top = 304
    Width = 75
    Height = 25
    Caption = #1057#1073#1088#1086#1089
    TabOrder = 3
    OnClick = Button3Click
  end
end
