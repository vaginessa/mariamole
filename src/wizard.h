#ifndef WIZARD_H
#define WIZARD_H

#include <QDialog>
#include <QString>
#include <QProcess>
#include <QTextStream>
#include <QDir>
#include <QFileInfo>
#include <QListWidgetItem>
#include <QDesktopWidget>

#include "ui_wizard.h"

#include "config.h"
#include "workspace.h"

class Wizard : public QDialog
{
	Q_OBJECT

public:
	Wizard(QWidget *parent = 0);
	~Wizard();

	bool ImportLibrary(void);
	bool NewProject(void);	
	QString GetLibraryName(void);

private:
	Ui::Wizard ui;

	bool ok;
	bool Display(void);
	void PopulateLibrariesList(void);
	void PopulateExamplesTree(void);
	void ListExamples(QStringList &examples);	
	void GetExamplesDirectoriesRecursivelly(QString path, QStringList &examples);
	void GetExamplesNamesRecursivelly(QString hierarchy, QString path, QStringList &examples);
	bool CreateTheSelectedProject(void);
	
	QString GetSelectedExamplePath(void);

private slots:
	void btnNextClicked(void);
	void btnPreviousClicked(void);
	void btnFinishClicked(void);
	void btnCancelClicked(void);
	void rbImportExample(void);
	void rbEmptyProject(void);
	void listLibsClicked (QListWidgetItem * item);
	void examplesTreeClicked (QTreeWidgetItem * item, int column);

};

#endif // WIZARD_H
