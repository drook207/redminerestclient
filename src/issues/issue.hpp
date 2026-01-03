#ifndef ISSUE_HPP
#define ISSUE_HPP

#include <qjsondocument.h>
#include <QJsonDocument>
#include <QList>
#include <qobject.h>
#include <qvariant.h>
#include <QVariantMap>
namespace redmine {
class Issue : public QObject {
    Q_OBJECT
  public:
    explicit Issue(QObject* parent = nullptr);
    void setJsonData(QJsonDocument& jsonData);
    void setIssueId(int issueId);
    [[nodiscard]] int issueId() const;

    [[nodiscard]] int subprojectId() const;
    void setSubprojectId(int newSubprojectId);

    [[nodiscard]] int projectId() const;
    void setProjectId(int newProjectId);

    [[nodiscard]] int trackerId() const;
    void setTrackerId(int newTrackerId);

    [[nodiscard]] int statusId() const;
    void setStatusId(int newStatusId);

    [[nodiscard]] int priorityId() const;
    void setPriorityId(int newPriorityId);

    [[nodiscard]] QString subject() const;
    void setSubject(const QString& newSubject);

    [[nodiscard]] QString description() const;
    void setDescription(const QString& newDescription);

    [[nodiscard]] int categoryId() const;
    void setCategoryId(int newCategoryId);

    [[nodiscard]] int fixedVersionId() const;
    void setFixedVersionId(int newFixedVersionId);

    [[nodiscard]] int assignedToId() const;
    void setAssignedToId(int newAssignedToId);

    [[nodiscard]] int parentIssueId() const;
    void setParentIssueId(int newParentIssueId);

    [[nodiscard]] QList<int> watcherUserIds() const;
    void setWatcherUserIds(const QList<int>& newWatcherUserIds);

    [[nodiscard]] bool isPrivate() const;
    void setIsPrivate(bool newIsPrivate);

    [[nodiscard]] float estimatedHours() const;
    void setEstimatedHours(float newEstimatedHours);

    [[nodiscard]] QVariantMap varianData() const;
    void setVarianData(const QVariantMap& newVarianData);

    [[nodiscard]] QJsonDocument jsonData() const;

  signals:
    void jsonDataChanged();
    void issueIdChanged();
    void subprojectIdChanged();
    void projectIdChanged();
    void trackerIdChanged();
    void statusIdChanged();
    void priorityIdChanged();
    void subjectChanged();
    void descriptionChanged();
    void categoryIdChanged();
    void fixedVersionChanged();
    void assigenedToIdChanged();
    void parentIssueIdChanged();
    void watchersUserIdsChanged();
    void isPrivateChanged();
    void estimatedHoursChanged();

    void fixedVersionIdChanged();

    void assignedToIdChanged();

    void watcherUserIdsChanged();

    void varianDataChanged();

  private:
    int m_issueId = -1;
    int m_subprojectId = -1;
    int m_projectId = -1;
    int m_trackerId = -1;
    int m_statusId = -1;
    int m_priorityId = -1;
    QString m_subject;
    QString m_description;
    int m_categoryId = -1;
    int m_fixedVersionId = -1;
    int m_assignedToId = -1;
    int m_parentIssueId = -1;
    QList<int> m_watcherUserIds;
    bool m_isPrivate;
    float m_estimatedHours;

    QVariantMap m_varianData;
    QJsonDocument m_jsonData;
    Q_PROPERTY(int issueId READ issueId WRITE setIssueId NOTIFY issueIdChanged FINAL)
    Q_PROPERTY(int subprojectId READ subprojectId WRITE setSubprojectId NOTIFY subprojectIdChanged FINAL)
    Q_PROPERTY(int projectId READ projectId WRITE setProjectId NOTIFY projectIdChanged FINAL)
    Q_PROPERTY(int trackerId READ trackerId WRITE setTrackerId NOTIFY trackerIdChanged FINAL)
    Q_PROPERTY(int statusId READ statusId WRITE setStatusId NOTIFY statusIdChanged FINAL)
    Q_PROPERTY(int priorityId READ priorityId WRITE setPriorityId NOTIFY priorityIdChanged FINAL)
    Q_PROPERTY(QString subject READ subject WRITE setSubject NOTIFY subjectChanged FINAL)
    Q_PROPERTY(QString description READ description WRITE setDescription NOTIFY descriptionChanged FINAL)
    Q_PROPERTY(int categoryId READ categoryId WRITE setCategoryId NOTIFY categoryIdChanged FINAL)
    Q_PROPERTY(int fixedVersionId READ fixedVersionId WRITE setFixedVersionId NOTIFY fixedVersionIdChanged FINAL)
    Q_PROPERTY(int assignedToId READ assignedToId WRITE setAssignedToId NOTIFY assignedToIdChanged FINAL)
    Q_PROPERTY(int parentIssueId READ parentIssueId WRITE setParentIssueId NOTIFY parentIssueIdChanged FINAL)
    Q_PROPERTY(QList<int> watcherUserIds READ watcherUserIds WRITE setWatcherUserIds NOTIFY watcherUserIdsChanged FINAL)
    Q_PROPERTY(bool isPrivate READ isPrivate WRITE setIsPrivate NOTIFY isPrivateChanged FINAL)
    Q_PROPERTY(float estimatedHours READ estimatedHours WRITE setEstimatedHours NOTIFY estimatedHoursChanged FINAL)
    Q_PROPERTY(QVariantMap varianData READ varianData WRITE setVarianData NOTIFY varianDataChanged FINAL)
    Q_PROPERTY(QJsonDocument jsonData READ jsonData WRITE setJsonData NOTIFY jsonDataChanged FINAL)
};

} // namespace redmine

#endif // ISSUE_HPP !
