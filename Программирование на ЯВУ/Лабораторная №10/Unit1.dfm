object Form1: TForm1
  Left = 263
  Top = 157
  BorderStyle = bsSingle
  Caption = 'Form1'
  ClientHeight = 491
  ClientWidth = 950
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnClick = FormClick
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Image1: TImage
    Left = 0
    Top = 0
    Width = 945
    Height = 489
    Transparent = True
    OnClick = FormClick
  end
  object Image2: TImage
    Left = 1
    Top = 352
    Width = 313
    Height = 121
    Transparent = True
    OnClick = FormClick
  end
  object Timer1: TTimer
    Enabled = False
    OnTimer = Timer1Timer
    Top = 272
  end
end
