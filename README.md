# rupc2016

git を install　します。(apt-get など cygwin ならhttp://qiita.com/kanpou_/items/0764381301d37e04157b )


github　アカウントを作ります。
僕がメールを送ります。

$ git config --global user.name "githubのユーザーネーム"

$ git config --global user.email "gitubub"


$ git clone git@github.com:satellitex/rupc2016.git

のコマンドをコマンドラインでうちます。

すると

rupc2016 といディレクトリができるのでそこが作業ディレクトリです。

自分が作ったものを反映させるとき

まず

$ git pull

をします。github側にあるデータをローカルに反映させます。
これをしないとこちら側からgituhubにあるデータを更新できないので必ずしてください。

$ git add 自分の編集したディレクトリやファイル

全てのファイルを反映させるときは

$ git add .


コミット

$ git commit -m 'メッセージ'

-m でメッセージを添えないとvimが開いたきがします。

$ git push

これで完全に反映完了

git push のときに謎のwarningがでることがあるが、その時は 指示にしたがって適当にコマンドを実行したあと
git push を再度実行するとwarningが消えることが多い。



簡略化
とりあいず

$ git add .

$ git commit -m 'message'

$ git pull

$ git push

をやればok
