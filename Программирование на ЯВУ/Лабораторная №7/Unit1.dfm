object Form1: TForm1
  Left = 192
  Top = 124
  Width = 430
  Height = 223
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
  object Panel1: TPanel
    Left = 16
    Top = 16
    Width = 201
    Height = 41
    TabOrder = 0
    object CSpinEdit1: TCSpinEdit
      Left = 8
      Top = 8
      Width = 97
      Height = 22
      TabOrder = 0
    end
    object Button1: TButton
      Left = 112
      Top = 8
      Width = 75
      Height = 25
      Caption = 'Button1'
      TabOrder = 1
      OnClick = Button1Click
    end
  end
  object StringGrid1: TStringGrid
    Left = 16
    Top = 80
    Width = 377
    Height = 41
    ColCount = 1
    FixedCols = 0
    RowCount = 1
    FixedRows = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing, goTabs]
    TabOrder = 1
    Visible = False
  end
  object Button2: TButton
    Left = 16
    Top = 136
    Width = 75
    Height = 25
    Caption = #1042#1099#1074#1086#1076
    TabOrder = 2
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 112
    Top = 136
    Width = 75
    Height = 25
    Caption = #1057#1073#1088#1086#1089
    TabOrder = 3
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 208
    Top = 136
    Width = 75
    Height = 25
    Caption = #1042#1099#1093#1086#1076
    TabOrder = 4
    OnClick = Button4Click
  end
end
