# 9号線系統用複数プラグイン両立プラグイン
`v2.02` (2023/11/29)
-----
このプラグインは小田急線プラグインとメトロ総合プラグインを両立するにあたり、インデックス変更を行い、またレバーサー情報を正常に渡すためのプラグイン。小田急線プラグイン、メトロ総合プラグインとの併用が前提。両プラグインの読み込み後にほかのプラグインを読み込むことができる。

本プラグインは[Rock_On様のdetailManager](https://github.com/mikangogo/DetailManager)のコードを改造し、作成した。

## 設定番号
必ず**付属の端子台を参照すること。**
### panelインデックス
- [端子台](https://docs.google.com/spreadsheets/d/1rsIOkY-5uuszAekwyyYBjYd1NrkQBQti/edit?usp=sharing&ouid=117001858782449869576&rtpof=true&sd=true)を参照すること。

### soundインデックス
- [端子台](https://docs.google.com/spreadsheets/d/1rsIOkY-5uuszAekwyyYBjYd1NrkQBQti/edit?usp=sharing&ouid=117001858782449869576&rtpof=true&sd=true)を参照すること。

### beaconインデックス
- [端子台](https://docs.google.com/spreadsheets/d/1rsIOkY-5uuszAekwyyYBjYd1NrkQBQti/edit?usp=sharing&ouid=117001858782449869576&rtpof=true&sd=true)を参照すること。

### signalインデックス
- 変更なし（裏機能として、汎用ATSの信号コードが読み込める）

### SWインデックス
- [端子台](https://docs.google.com/spreadsheets/d/1rsIOkY-5uuszAekwyyYBjYd1NrkQBQti/edit?usp=sharing&ouid=117001858782449869576&rtpof=true&sd=true)を参照すること。

### 設定ファイル（**v2.02から変更**）
- ファイル名は`MetropiLoader.ini`にすること。
- 設定項目は[端子台](https://docs.google.com/spreadsheets/d/1rsIOkY-5uuszAekwyyYBjYd1NrkQBQti/edit?usp=sharing&ouid=117001858782449869576&rtpof=true&sd=true)を参照すること。

### プラグイン指定ファイル
- ファイル名は`DetailModules.txt`とすること。
- 1番上の行には、`小田急線用プラグインへの相対パス`を記入すること。
- 2番目の行には、`メトロ総合プラグインへの相対パス`を記入すること。
- 3行目以下の行には、detailmanagerと同様、読み込みたいPIを読み込みたい順に記入すること。

### その他
- 詳細は[Excelシート](https://docs.google.com/spreadsheets/d/1rsIOkY-5uuszAekwyyYBjYd1NrkQBQti/edit?usp=sharing&ouid=117001858782449869576&rtpof=true&sd=true)（付属もあり）を参照し、シートを参考に設定すること。
- 一般機能、OM-ATSなど一部機能は[Wiki](https://github.com/susLine2320/MetropiLoader/wiki)に解説を記載しているので参考のこと。

## 著作権
何かしらのライセンスを設定しているわけではないが、単体・無改造での再配布は不可。改造の上別の用途で使用・公開する場合、必ず事前に連絡すること。

無改造の上車両データに同封する場合、上述のPIと両立して使う場合に限り事前連絡不要。なお当方の把握のため、事後に必ず連絡すること。

## 更新日時
### Translate_oerA時代
- 2020/01/18 v0.1　インデックスを一部変更した。（jsc.dll）
- 2023/01/18?    v0.1　小田急PI変換機能搭載
- 2023/02/09     v0.2　回生開放使用選択機能搭載
### MetropiLoader時代
#### 2023/03/07 v2.0
- A/B、及びdetailmanagerを統合。一つのPIとして扱いやすく。
- 22番地上子関連の問題修正。またTIS表示を一部両PIで統合。
- キー配置を使いやすく（一部機能の分離）
#### 2023/08/10 v2.01 
- OM-ATSの地上子配列をデフォルト準拠に変更。
- 車掌電鈴を改善。

#### 2023/11/29 v2.02
- 大幅なインデックス変更及び機能統合。
- 回生開放機能を再内包。その他うさプラ未実装機能を実装。
- 設定調整を可能に。
- ATS-S，ATS-P，（東武西武東急ATS）にも対応。

## Author
- Twitter [@16000land](https://twitter.com/16000land)
- Web [Github.io](https://susline2320.github.io/)
- Mail [Gmail](mailto:chiyoda16122@gmail.com)

©Line-16 2018-2023